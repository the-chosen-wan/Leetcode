#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int main(){
    int n;
    cout << "Enter number of vertices"<<endl;
    cin>>n;

    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int l = ceil(log2(n));
    vector<vector<int>> dp(n,vector<int>(l+1,0));
    vector<int> tin(n,0);vector<int> tout(n,0);int timer=0;

    auto dfs  = [&](int src,int p,auto&& dfs)->void{
        tin[src]=++timer;
        dp[src][0]=p;
        for(int i=1;i<=l;i++)
            dp[src][i] = dp[dp[src][i-1]][i-1];
        
        for(int v:adj[src]){
            if(v!=p)
                dfs(v,src,dfs);
        }
        tout[src]=++timer;
        return;
    };

    auto is_ancestor = [&](int u,int v)->bool{
        return tin[u]<=tin[v]&&tout[u]>=tout[v];
    };

    auto lca = [&](int u,int v)->int{
        if(is_ancestor(v,u))
            return v;
        if(is_ancestor(u,v))
            return u;
        for(int i=l;i>=0;i--){
            if(!is_ancestor(dp[u][i],v))
                u = dp[u][i];
        }
        return dp[u][0];
    };

    dfs(0,0,dfs);
    int u,v;cin>>u>>v;
    cout<<lca(u,v)<<endl;
    return 0;
}