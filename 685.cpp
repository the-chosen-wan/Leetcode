#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

void initialize(int vertices, vector<int> &parent, vector<int> &rank1)
{
    parent.resize(vertices);
    rank1.resize(vertices);
    for (int i = 0; i < vertices; i++)
    {
        parent[i] = i;
        rank1[i] = 0;
    }
}
int find_parent(int v, vector<int> &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_parent(parent[v], parent);
}
void union_set(int v1, int v2, vector<int> &parent, vector<int> &rank1)
{
    v1 = find_parent(v1, parent);
    v2 = find_parent(v2, parent);
    if (rank1[v1] < rank1[v2])
        parent[v1] = v2;
    else if (rank1[v1] > rank1[v2])
        parent[v2] = v1;
    else
    {
        parent[v1] = v2;
        rank1[v2]++;
    }
}

vector<int> redundant(vector<vector<int>>& edges){
    int n = -inf;
    for(vector<int> edge:edges){
        n = max(n,edge[0]);
        n = max(n,edge[1]);
    }

    vector<int> in_degree(n,0);
    for(vector<int> edge:edges){
        in_degree[edge[1]]++;
        if(in_degree[edge[1]]==2)
            return edge;
    }

    vector<int> parent(n);
    vector<int> rank(n);
    initialize(n,parent,rank);

    int ind = 0;
    for(int i=0;i<edges.size();i++){
        if(find_parent(edges[i][0]-1,parent)!=find_parent(edges[i][1]-1,parent))
            union_set(edges[i][0]-1,edges[i][1]-1,parent,rank);
        else{
            ind = i;
            break;
        }
    }
    return edges[ind];
}

class Solution
{
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        return redundant(edges);
    }
};