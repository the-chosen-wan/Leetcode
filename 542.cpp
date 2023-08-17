#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
using pii=pair<int,int>;
#define pb push_back
#define mp make_pair

vector<vector<int>> ans(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> adj(n*m+1);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int val = i*m + j;

            int val1 = (i-1)*m + j;
            int val2 = i*m + j-1;
            int val3 = (i+1)*m + j;
            int val4 = i*m + j + 1;

            if(i>0)
                adj[val].pb(val1);
            if(i<n-1)
                adj[val].pb(val3);
            
            if(j>0)
                adj[val].pb(val2);
            
            if(j<m-1)
                adj[val].pb(val4);
            
            if(grid[i][j]==0)
                adj[n*m].pb(val);
        }
    }

    vector<int> vis(n*m+1,-1);

    queue<int> q;
    q.push(n*m);
    vis[n*m] = 0;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(int v:adj[front]){
            if(vis[v]==-1){
                vis[v] = vis[front]+1;
                q.push(v);
            }
        }
    }

    vector<vector<int>> ans(n,vector<int>(m,-1));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[i][j] = vis[i*m+j]-1;
        }
    }

    return ans;

}

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        return ans(mat);
    }
};