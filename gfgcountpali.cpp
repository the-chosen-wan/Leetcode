#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include<chrono>
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

ll ans(string s){
    int n = s.length();

    vector<vector<int>> dp(n,vector<int>(n,-1));

    auto dfs = [&](int i,int j,auto&& dfs)->int{
        if(i>=j)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==s[j])
            dp[i][j] = dfs(i+1,j-1,dfs);
        else
            dp[i][j] = 0;
        return dp[i][j];
    };

    dfs(0,n-1,dfs);

    vector<vector<ll>> ans(n,vector<ll>(n,-1));

    auto dfs1 = [&](int i,int j,auto&& dfs1)->ll{
        if(i>=j)
            return 1;
        
        if(ans[i][j]!=-1)
            return ans[i][j];
        
        if(s[i]==s[j]){
            ans[i][j] = (1+dfs1(i+1,j,dfs1) + dfs1(i,j-1,dfs1))%inf;
        }
        else
            ans[i][j] = (dfs1(i+1,j,dfs1)+dfs1(i,j-1,dfs1))%inf;

        return ans[i][j];
    };

    return dfs1(0,n-1,dfs1);
}

class Solution {
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       return ans(str);
    }
};

