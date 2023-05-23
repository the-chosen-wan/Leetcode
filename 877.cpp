#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool ans(vector<int>& piles){
    int n = piles.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));

    vector<int> prefsum(n,0);

    prefsum[0] = piles[0];

    for(int i=1;i<n;i++)
        prefsum[i] = prefsum[i-1]+piles[i];

    auto query = [&](int l,int r)->int{
        if(l==0)
            return prefsum[r];
        return prefsum[r]-prefsum[l-1];
    };

    auto dfs = [&](int i,int j,auto&& dfs)->int{
        if(i==j)
            return dp[i][j]=piles[i];

        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int l1 = dfs(i+1,j,dfs);
        int l2 = dfs(i,j-1,dfs);

        dp[i][j] = max(piles[i]+query(i+1,j)-l1,piles[j]+query(i,j-1)-l2);
        return dp[i][j];
    };

    int k = dfs(0,n-1,dfs);

    if(k>query(0,n-1)-k)
        return true;
    return false;
}

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return ans(piles);
    }
};