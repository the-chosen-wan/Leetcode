#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int>& parents){
    int n = parents.size();
    vector<vector<int>> adj(n);

    for(int i=1;i<n;i++){
        adj[i].pb(parents[i]);
        adj[parents[i]].pb(i);
    }

    vector<ll> size(n,0);
    vector<ll> prod(n,1);

    ll maxa=-inf;

    auto dfs = [&](int src,int par,auto&& dfs)->ll{
        size[src]=1;

        ll product=1;

        for(int v:adj[src]){
            if(v!=par){
                size[src]+=dfs(v,src,dfs);
                product*=size[v];
            }
        }

        prod[src]=(product*(src==0?1:(n-size[src])));
        maxa = max<ll>(maxa,prod[src]);
        return size[src];
    };

    dfs(0,0,dfs);

    int cnt=0;
    for(int i=0;i<n;i++){
        if(prod[i]==maxa)
            cnt++;
    }

    return cnt;
}

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        return ans(parents);
    }
};