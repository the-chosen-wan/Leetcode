#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

struct edge
{
    int weight;
    int from;
    int to;

    edge(int weight, int from, int to)
    {
        this->weight = weight;
        this->from = from;
        this->to = to;
    }

    bool operator<(const edge &e)
    {
        return this->weight < e.weight;
    }
};

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

bool comp(pair<edge, int> &e1, pair<edge, int> &e2)
{
    if (e1.first.weight == e2.first.weight)
        return e1.second < e2.second;
    return e1.first < e2.first;
}

vector<bool> ans(int n, vector<vector<int>> &edges, vector<vector<int>> &queries)
{
    vector<int> parent;
    vector<int> rank;
    initialize(n, parent, rank);

    vector<edge> e;
    for (vector<int> &v : edges)
        e.pb(edge(v[2], v[0], v[1]));

    sort(e.begin(), e.end());

    vector<pair<edge, int>> q;
    for (int i = 0; i < queries.size(); i++)
        q.pb(mp(edge(queries[i][2], queries[i][0], queries[i][1]), i));

    sort(q.begin(), q.end(), comp);
    vector<bool> ans(queries.size());
    int c = 0;

    for (int i = 0; i < q.size(); i++)
    {
        while (c < e.size() && e[c].weight < q[i].first.weight)
        {
            union_set(e[c].from, e[c].to, parent, rank);
            c++;
        }

        int u = q[i].first.to;
        int v = q[i].first.from;
        if (find_parent(u, parent) == find_parent(v, parent))
            ans[q[i].second] = true;
        else
            ans[q[i].second] = false;
    }
    return ans;
}

class Solution
{
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        return ans(n, edgeList, queries);
    }
};
