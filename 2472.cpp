#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

int ans(string s,int k){
    int n = s.size();

    vector<vector<int>> dp(n,vector<int>(n,-1));

    auto dfs = [&](int i,int j,auto&& dfs)->int{
        if(i>j)
            return 1;

        if(i==j){
            dp[i][j]=1;
            return dp[i][j];
        }

        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==s[j])
            dp[i][j] = dfs(i+1,j-1,dfs);
        else
            dp[i][j]=0;
        return dp[i][j];
    };
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(dp[i][j]==-1)
                dfs(i,j,dfs);
        }
    }

    vector<int> ans(n,-1);

    auto dfs1 = [&](int i,auto&& dfs1)->int{
        if(i<k-1){
            if(i>=0)
                ans[i]=0;
            return 0;
        }

        if(ans[i]!=-1)
            return ans[i];
        
        int ret = -1;
        for(int j=k;j<=i+1;j++){
            if(dp[i-j+1][i]){
                ret = max(ret,1+dfs1(i-j,dfs1));
            }
        }
        ret = max(ret,dfs1(i-1,dfs1));
        ans[i] = ret;
        return ans[i];
    };

    return dfs1(n-1,dfs1);
}

class Solution {
public:
    int maxPalindromes(string s, int k) {
        return ans(s,k);
    }
};