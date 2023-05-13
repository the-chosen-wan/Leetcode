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

struct edge{
    int from;
    int to;
    int weight;
    bool included;
    int index;
    
    edge(int from,int to,int weight,bool included,int index){
        this->from = from;
        this->to = to;
        this->weight = weight;
        this->included = included;
        this->index = index;
    }

    bool operator<(const edge &edge2)
    {
        return this->weight < edge2.weight;
    }
};

int return_mst(vector<edge>&edges,vector<int>& indices,int n){
    vector<int> parent;
    vector<int> rank;
    initialize(n,parent,rank);
    int c = 0;int sum =0;
    for(int i=0;i<edges.size();i++){
        if(c>=n)
            return sum;
        int from = edges[i].from;
        int to = edges[i].to;
        int w = edges[i].weight;
        bool include = edges[i].included;

        if(include){
            if(find_parent(from,parent)==find_parent(to,parent))
                continue;
            sum+=w;
            indices.pb(edges[i].index);
            union_set(to,from,parent,rank);
        }
    }
    return -1;
}

vector<vector<int>> crit(int n,vector<vector<int>>&ed){
    vector<edge> edges;
    for(int i=0;i<ed.size();i++)
        edges.pb(edge(ed[i][0],ed[i][1],ed[i][2],true,i));
    
    vector<vector<int>> ans(2);
    sort(edges.begin(),edges.end());

    vector<int> indices;
    int mst = return_mst(edges,indices,n);

    vector<int> indic = indices;
    for(int i:indic){
        for(edge& e:edges){
            if(e.index==i){
                e.included = false;
                int sum = return_mst(edges,indices,n);
                if(sum==mst)
                    ans[1].pb(e.index);
                else 
                    ans[0].pb(e.index);
                e.included = true;
                break;
            }
        }
    }
    return ans;
}

class Solution
{
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        return crit(n,edges);
    }
};
