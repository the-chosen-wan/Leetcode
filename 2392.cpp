#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

vector<vector<int>> ans(int k,vector<vector<int>>& row,vector<vector<int>>& column){
    vector<vector<int>> rowadj(k+1);
    vector<vector<int>> coladj(k+1);
    vector<vector<int>> ans;

    for(vector<int>& r:row)
        rowadj[r[0]].pb(r[1]);
    for(vector<int>& c:column)
        coladj[c[0]].pb(c[1]);
    
    vector<int> rowcount(k+1,0);
    vector<int> colcount(k+1,0);
    vector<int> vis(k+1,0);
    bool cycle = false;
    int cnt=k-1;

    auto dfs1=[&](int src,auto&& dfs1)->void{
        if(cycle)
            return;
        vis[src]=1;

        for(int v:rowadj[src]){
            if(vis[v]==1)
                cycle=true;
            if(vis[v]==0){
                dfs1(v,dfs1);
            }
        }
        vis[src]=2;
        rowcount[src] = cnt--;
        return;
    };

    auto dfs2 = [&](int src, auto &&dfs2) -> void
    {
        if (cycle)
            return;
        vis[src] = 1;

        for (int v : coladj[src])
        {
            if (vis[v] == 1)
                cycle = true;
            if (vis[v] == 0)
            {
                dfs2(v, dfs2);
            }
        }
        vis[src] = 2;
        colcount[src] = cnt--;
        return;
    };

    for(int i=1;i<=k;i++){
        if(!vis[i])
            dfs1(i,dfs1);
    }

    vis.assign(k + 1, 0);
    cnt = k-1;

    for(int i=1;i<=k;i++){
        if(!vis[i])
            dfs2(i,dfs2);
    }

    if(cycle)
        return ans;
    
    ans.resize(k,vector<int>(k,0));

    for(int i=1;i<=k;i++)
        ans[rowcount[i]][colcount[i]]=i;
    return ans;
}

class Solution
{
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        return ans(k,rowConditions,colConditions);
    }
};