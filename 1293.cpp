#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

void mindist(int src,int n,int m,vector<vector<int>>& adj,vector<vector<int>>& dist){
    int k = adj.size();
    int i=src/m;
    int j = src - (i)*m;
    dist[src][src]=0;
    queue<int> q;

    int val1 = (i+1)*m+j;
    int val2 = i*m+j+1;
    int val3 = (i-1)*m+j;
    int val4 = i*m+j-1;

    if(i+1<n)
        {q.push(val1);dist[src][val1]=1;}
    if(j+1<m)
        {q.push(val2);dist[src][val2]=1;}
    if(i>0)
        {q.push(val3);dist[src][val3]=1;}
    if(j>0)
        {q.push(val4);dist[src][val4]=1;}
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(int v:adj[front]){
            if(dist[src][v]==inf)
            {q.push(v);dist[src][v]=++dist[src][front];}
        }
    }

    return;
}

int ans(vector<vector<int>>& grid,int k){
    int n  = grid.size();
    int m  = grid[0].size();
    int num = n*m;
    vector<vector<int>> adj(num);
    vector<int> blocked;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1)
                {blocked.pb(i*m+j);continue;}
            int val = i*m + j;
            int val1 = (i-1)*m+j;
            int val2 = (i+1)*m+j;
            int val3 = i*m+j+1;
            int val4 = i*m+j-1;
            if(i>0)
                adj[val].pb(val1);
            if(j>0)
                adj[val].pb(val4);
            if(i+1<n)
                adj[val].pb(val2);
            if(j+1<m)
                adj[val].pb(val3);
        }
    }

    
}