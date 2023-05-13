#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

void dfs(int par,int src, vector<vector<int>>& adj, vector<int>& dz, vector<int>& sz){
    dz[src] = 1;
    sz[src] = 0;

    for(int k:adj[src]){
        if(k!=par){
            dfs(src,k,adj,dz,sz);
            dz[src]+=dz[k];
            sz[src]+=(dz[k]+sz[k]);
        }
    }
    return;
}

void dfs1(int par,int src,vector<vector<int>>& adj,vector<int>& dz,vector<int>& sz){
    if(par!=src)
        sz[src] = adj.size()-2*dz[src] + sz[par];
    
    for(int k:adj[src]){
        if(k!=par)
            dfs1(src,k,adj,dz,sz);
    }
    return;
}

vector<int> ans(int n,vector<vector<int>>& edges){
    vector<int> dz(n);
    vector<int> sz(n);
    vector<vector<int>> adj(n);

    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].pb(edges[i][1]);
        adj[edges[i][1]].pb(edges[i][0]);
    }

    dfs(0,0,adj,dz,sz);
    dfs1(0,0,adj,dz,sz);
    return sz;
}

class Solution
{
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        return ans(n,edges);
    }
};