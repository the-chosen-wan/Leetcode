#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

ll ans(vector<vector<int>>& roads,int seats){
    int m = roads.size();

    int n = -inf;

    if(m==0)
        return 0;
    for(int i=0;i<m;i++){
        n = max({n,roads[i][0],roads[i][1]});
    }

    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++){
        adj[roads[i][0]].pb(roads[i][1]);
        adj[roads[i][1]].pb(roads[i][0]);
    }

    vector<ll> size(n+1,0);
    vector<ll> numcars(n+1,0);
    ll totalcost=0;
    auto dfs=[&](int src,int par,auto&& dfs)->ll{
        size[src] = 1;

        for(int v:adj[src]){
            if(v!=par){
                size[src]+=dfs(v,src,dfs);
                totalcost+=numcars[v];
            }
        }

        numcars[src] = ceil((double)(size[src])/(double)seats);
        return size[src];
    };
    dfs(0,0,dfs);
    return totalcost;
}

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        return ans(roads,seats);
    }
};