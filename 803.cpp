#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
const int p = 31;
#define pb push_back
#define mp make_pair


int find_sets(int v, vector<int> &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_sets(parent[v], parent);
}

void union_sets(int a,int b,vector<int>& parent,vector<int>& size,vector<int>& isfell){
    a = find_sets(a, parent);
    b = find_sets(b, parent);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        isfell[a]|=isfell[b];
    }
}

vector<int> ans(vector<vector<int>>& grid,vector<vector<int>>& hits){
    int n=grid.size();
    int m = grid[0].size();

    unordered_set<int> exclude;
    
    int h = hits.size();
    for(int i=0;i<h;i++)
        exclude.insert(hits[i][0]*m+hits[i][1]);

    vector<int> parent,size,isfell;
    parent.resize(n*m);size.resize(n*m);isfell.resize(n*m);

    for(int i=0;i<n*m;i++){
        parent[i]=i;
        size[i]=1;
        if((i/m)==0)
            isfell[i]=1;
        else 
            isfell[i]=0;
    }

    vector<vector<int>> adj(n*m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0)
                continue;
            int val=i*m+j;

            if(exclude.find(val)!=exclude.end())
                continue;
            int val1=(i+1)*m+j;
            int val2=i*m+j+1;

            if(i+1<n&&grid[i+1][j]!=0&&exclude.find(val1)==exclude.end())
                union_sets(val,val1,parent,size,isfell);
        }
    }
}

