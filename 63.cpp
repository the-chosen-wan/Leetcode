#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<ll>> dp(n,vector<ll>(m,-1));

    auto dfs = [&](int i,int j,auto&& dfs )->ll{
        if(i>=n||j>=m){
            return 0;
        }

        if(dp[i][j]!=-1)
            return dp[i][j];

        if(i==n-1&&j==m-1&&!grid[i][j]){
            dp[i][j]=1;
            return 1;
        }

        if(grid[i][j]){
            dp[i][j]=0;
            return 0;
        }

        dp[i][j] = 0;
        dp[i][j]+=dfs(i+1,j,dfs);
        dp[i][j]+=dfs(i,j+1,dfs);
        return dp[i][j];
    };

    return dfs(0,0,dfs);
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return ans(obstacleGrid);
    }
};

