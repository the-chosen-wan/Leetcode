#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

int ans(int n,vector<vector<int>>& edges,vector<int>& price){
    vector<vector<int>> adj(n);

    for(int i=0;i<n-1;i++){
        adj[edges[i][0]].pb(edges[i][1]);
        adj[edges[i][1]].pb(edges[i][0]);
    }

    vector<ll> maxpath(n,-inf);
    vector<ll> secondmax(n,-inf);
    ll ans = -inf;

    auto dfs = [&](int src,int par,auto&& dfs)->void{
        ll maxa = -inf;
        ll secondmaxa=-inf;

        for(int node:adj[src]){
            if(node!=par){
                dfs(node,src,dfs);

                if(maxa!=-inf)
                    ans = max<ll>(ans,secondmax[node]+maxa+price[src]);
                
                if(secondmaxa!=-inf)
                    ans = max<ll>(ans,maxpath[node]+secondmaxa+price[src]);
                
                maxa = max<ll>(maxa,maxpath[node]);
                secondmaxa=max<ll>(secondmaxa,secondmax[node]);
            }
        }

        if(maxa==-inf)
            maxa=0;
        
        if(secondmaxa==-inf)
            secondmaxa=-price[src];

        ans = max(ans,maxa);
        maxpath[src] = price[src]+maxa;
        secondmax[src] = price[src]+secondmaxa;
        ans = max(ans,secondmax[src]);
        return;
    };

    dfs(0,0,dfs);
    return ans;
}

class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        return ans(n,edges,price);
    }
};