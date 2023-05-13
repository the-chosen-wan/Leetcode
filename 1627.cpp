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

vector<bool> connected(int n, int thresh, vector<vector<int>> &queries)
{
    vector<int> parent;
    vector<int> rank;

    initialize(n + 1, parent, rank);
    for (int i = thresh + 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            union_set(i, j, parent, rank);
        }
    }

    vector<bool> ans;
    for (vector<int> q : queries)
    {
        if (find_parent(q[0], parent) == find_parent(q[1], parent))
            ans.pb(true);
        else
            ans.pb(false);
    }

    return ans;
}

class Solution
{
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>> &queries)
    {
        return connected(n, threshold, queries);
    }
};