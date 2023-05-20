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

int ans(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> adj(n*m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            int val = m*i+j;
            int val1 = m*(i+1)+j+1;
            int val2 = m*i+j+1;
            int val3 = m*(i-1) + j+1;

            if(i!=0&&grid[i][j]<grid[i-1][j+1])
                adj[val].pb(val3);
            
            if(i!=n-1&&grid[i][j]<grid[i+1][j+1])
                adj[val].pb(val1);
            
            if(grid[i][j]<grid[i][j+1])
                adj[val].pb(val2);
        }
    }

    vector<int> dp(n*m,-1);

    auto dfs = [&](int src,auto&& dfs)->int{
        if(dp[src]!=-1)
            return dp[src];

        int ret = 0;

        for(int node:adj[src])
            ret=max(ret,dfs(node,dfs));
        
        ret+=1;
        
        dp[src]=ret;
        return ret;
    };

    int maxa = 0;
    
    for(int j=0;j<n;j++){
        int ans=dfs(m*j,dfs);--ans;
        maxa = max(ans,maxa);
    }
    
    return maxa;
}

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        return ans(grid);
    }
};