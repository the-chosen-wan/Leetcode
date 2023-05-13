#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

void initialize(int n, vector<int> &parent, vector<int> &size)
{
    parent.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
    return;
}

int find_sets(int v, vector<int> &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_sets(parent[v], parent);
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &size)
{
    a = find_sets(a, parent);
    b = find_sets(b, parent);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int ans(vector<vector<int>>& grid){
    int n = grid[0].size();
    vector<int> parent,size;
    initialize(n*n,parent,size);
    vector<pii> zeropos;
    int c=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                c++;
                int val1 = i*n+j;
                int val2 = (i+1)*n+j;
                int val3 = i*n+j+1;
                if(i+1<n&&grid[i+1][j]==1)
                    union_sets(val1,val2,parent,size);
                if(j+1<n&&grid[i][j+1]==1)
                    union_sets(val1,val3,parent,size);
            }
            else{
                zeropos.pb(mp(i,j));
            }
        }
    }

    int maxa = -inf;
    if(c!=0)
        maxa = *max_element(size.begin(),size.end());
    
    for(pii& e:zeropos){
        vector<int> neighbours;
        int i=e.first;int j=e.second;
        int val2 = (i+1)*n+j;
        int val3 = (i-1)*n+j;
        int val4 = i*n+j+1;
        int val5 = i*n+j-1;

        if(i+1<n&&grid[i+1][j]==1)
            neighbours.pb(find_sets(val2,parent));
        if(i>0&&grid[i-1][j]==1)
            neighbours.pb(find_sets(val3,parent));
        if(j+1<n&&grid[i][j+1]==1)
            neighbours.pb(find_sets(val4,parent));
        if(j>0&&grid[i][j-1]==1)
            neighbours.pb(find_sets(val5,parent));
        int ret=1;
        if(!neighbours.empty()){
            unordered_set<int> s(neighbours.begin(),neighbours.end());
            for(int v:s)
                ret+=size[v];
        }
        maxa = max(ret,maxa);
    }
    return maxa;
}

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        return ans(grid);
    }
};