#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &tin, vector<int> &low, set<pii> &s, int &timer,int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v])
    {
        if (to == p)
            continue;
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(adj, visited, tin, low, s, timer,to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                {s.insert(mp(v,to));s.insert(mp(to,v));}
        }
    }
}

void initialize(int n,vector<int>& parent,vector<int>& size){
    parent.resize(n);
    size.resize(n);
    for(int i=0;i<n;i++){
        parent[i] = i;
        size[i]=1;
    }
    return;
}

int find_sets(int v,vector<int>& parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_sets(parent[v],parent);
}

void union_sets(int a, int b,vector<int>& parent,vector<int>& size)
{
    a = find_sets(a,parent);
    b = find_sets(b,parent);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

ll ans(int N,int M,vector<vector<int>>& edg){
    vector<vector<int>> adj(N);
    for (auto& t:edg){
        t[0]--;
        t[1]--;
    }
    vector<pii> edges;
    for(int i=0;i<edg.size();i++)
        {adj[edg[i][0]].pb(edg[i][1]);adj[edg[i][1]].pb(edg[i][0]);edges.pb(mp(edg[i][0],edg[i][1]));}
    vector<bool> visited(N,false);
    vector<int> tin(N,-1);
    vector<int> low(N,-1);
    int timer = 0;
    set<pii> s;
    dfs(adj,visited,tin,low,s,timer,0);
    vector<int> parent;
    vector<int> size;
    initialize(N,parent,size);
    ll ret = 0;

    for(pii e:edges){
        if(s.find(e)==s.end())
            {union_sets(e.first,e.second,parent,size);}
    }

    for(pii e:s){
        int p1 = find_sets(e.first,parent);
        int p2 = find_sets(e.second,parent);
        ret+=size[p1]*size[p2];
    }
    return ret/2;
}
int main(){
    int N = 8;
    int M = 8;
    vector<vector<int>> edges = {{1,6},{2,7},{3,8},{4,5},{1,2},{2,3},};
    cout<<ans(N,M,edges);
}
