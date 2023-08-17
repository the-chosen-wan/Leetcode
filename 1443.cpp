#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

int ans(int n,vector<vector<int>>& edges,vector<bool>& hasApple){
    vector<vector<int>> adj(n);
    int m = edges.size();

    for(int i=0;i<m;i++){
        adj[edges[i][0]].pb(edges[i][1]);
        adj[edges[i][1]].pb(edges[i][0]);
    }

    vector<bool> subtreeApple(n,false);
    vector<int> cost(n,0);

    auto dfs = [&](int src,int par,auto&& dfs)->void{
        subtreeApple[src] = hasApple[src];
        for(int v:adj[src]){
            if(v!=par){
                dfs(v,src,dfs);

                if(subtreeApple[v]){
                    cost[src]+=(2+cost[v]);
                    subtreeApple[src]=true;
                }
            }
        }
    };

    dfs(0,0,dfs);
    return cost[0];
}

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        return ans(n,edges,hasApple);
    }
};