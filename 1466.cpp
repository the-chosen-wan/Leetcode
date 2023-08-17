#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(int n,vector<vector<int>>& edges){
    int m = edges.size();

    vector<vector<pii>> adj(n);

    for(int i=0;i<m;i++){
        adj[edges[i][0]].pb(mp(edges[i][1],1));
        adj[edges[i][1]].pb(mp(edges[i][0],0));
    }
    
    int cnt=0;

    auto dfs=[&](int src,int par,auto&& dfs)->void{

        for(pii v:adj[src]){
            if(v.first!=par){
                cnt+=v.second;
                dfs(v.first,src,dfs);
            }
        }

        return;
    };
    dfs(0,0,dfs);
    return cnt;
}

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        return ans(n,connections);
    }
};