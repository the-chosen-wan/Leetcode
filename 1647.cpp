#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int ans(int n1,vector<vector<int>>& path){
    int n = path.size();
    map<pii,int> mappa;

    for(int i=0;i<n;i++){
        int m = path[i].size();
        for(int j=0;j<m-1;j++)
            mappa[mp(path[i][j],path[i][j])]++;
    }

    vector<vector<int>> adj(n1);
    vector<vector<int>> rev(n1);

    for(auto e:mappa){
        if(mappa[e.first]==n)
            {adj[e.first.first].pb(e.first.second);rev[e.first.second].pb(e.first.first);}
    }

    vector<pii> tout(n1);
    vector<bool> visited(n1,false);
    int c = 0;
    auto dfs1 = [&](int v,auto&& dfs1)->void{
        c++;
        for(int k:rev[v])
            if(!visited[k])
                dfs1(k,dfs1);
        tout[v] = mp(c,v);
        return;
    };

    for(int i=0;i<n1;i++)
        if(!visited[i])
            dfs1(i,dfs1);
    sort(tout.begin(),tout.end(),greater<pii>());

    int connect = 0;
    vector<int> id(n1);
    unordered_map<int, int> sizes;
    visited.assign(n1,false);
    auto dfs2 = [&](int v,auto&& dfs)->void{
        for(int k:adj[v])
            if(!visited[k])
                dfs2(k,dfs2);
        mappa[connect]++;
        id[v] = connect;
    }
    
}