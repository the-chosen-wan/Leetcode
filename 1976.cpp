#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll,int>;
const ll inf = (1e15) + 7;
const int mod = (1e9)+7;
#define pb push_back
#define mp make_pair

int ans(int n,vector<vector<int>>& edges){
    int m = edges.size();
    
    vector<vector<pii>> adj(n);
    vector<ll> mindist(n,inf);
    mindist[0] = 0;

    for(int i=0;i<m;i++){
        adj[edges[i][0]].pb(mp(edges[i][1],edges[i][2]));
        adj[edges[i][1]].pb(mp(edges[i][0],edges[i][2]));
    }

    set<pll> setta;
    setta.insert(mp(0,0));

    while(!setta.empty()){
        auto frontptr = setta.begin();
        pii front = *frontptr;
        setta.erase(frontptr);

        for(pii v:adj[front.second]){
            if(mindist[front.second]+v.second < mindist[v.first]){
                setta.erase(mp(mindist[v.first],v.first));
                mindist[v.first]=mindist[front.second]+v.second;
                setta.insert(mp(mindist[v.first],v.first));
            }
        }
    }

    if(mindist[n-1]==inf)
        return 0;
    
    vector<vector<int>> minadj(n);

    for(int i=0;i<n;i++){
        if(mindist[i]!=inf){
            for(pii v:adj[i]){
                if(mindist[i]+v.second==mindist[v.first]){
                    minadj[i].pb(v.first);
                }
            }
        }
    }

    ll ans = 0;
    vector<ll> dp(n,-1);
    auto dfs = [&](int src,auto&& dfs)->ll{
        if(src==n-1)
            return 1;
        
        if(dp[src]!=-1)
            return dp[src];
        
        dp[src]=0;
        for(int v:minadj[src]){
            dp[src] = (dp[src]+dfs(v,dfs))%mod;
        }
        return dp[src];
    };

    return dfs(0,dfs);
}

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        return ans(n,roads);
    }
};