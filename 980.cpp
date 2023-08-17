#include <iostream>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
#define N 16

int ans(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n,vector<bool>(m,false));

    int cnt=0;

    auto dfs = [&](int x,int y,auto&& dfs)->void{
        if(x<0||x>=n)
            return;

        if(y<0||y>=n)
            return;

        if(grid[x][y]==-1)
            return;
        
        if(grid[x][y]==2){
            cnt+=1;
            return;
        }

        if(visited[x][y])
            return;

        visited[x][y]=true;

        dfs(x+1,y,dfs);
        dfs(x,y+1,dfs);
        dfs(x-1,y,dfs);
        dfs(x,y-1,dfs);
        
        visited[x][y]=false;
        return;
    };

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1)
                dfs(i,j,dfs);
        }
    }
    return cnt;
}

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        return ans(grid);
    }
};