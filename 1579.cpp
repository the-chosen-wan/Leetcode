#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

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

int maximum(int n, vector<vector<int>> &edges)
{
    int len = edges.size();
    vector<pii> a_edges;
    vector<pii> b_edges;
    vector<pii> all_edges;

    for (int i = 0; i < len; i++)
    {
        if (edges[i][0] == 1)
            a_edges.push_back(make_pair(edges[i][1] - 1, edges[i][2] - 1));
        else if (edges[i][0] == 2)
            b_edges.push_back(make_pair(edges[i][1] - 1, edges[i][2] - 1));
        else
            all_edges.push_back(make_pair(edges[i][1] - 1, edges[i][2] - 1));
    }

    vector<int> a_parent, a_rank;
    vector<int> b_parent, b_rank;
    vector<int> all_parent, all_rank;

    initialize(n, a_parent, a_rank);
    initialize(n, b_parent, b_rank);
    initialize(n, all_parent, all_rank);

    int count = 0;

    for (pii e : all_edges)
    {
        int from = e.first;
        int to = e.second;

        if (find_parent(from, all_parent) == find_parent(to, all_parent))
            continue;
        union_set(from, to, all_parent, all_rank);
        count++;
        if (count == n - 1)
            break;
    }

    int count_a = 0;
    int count_b = 0;

    vector<int> temp_parent = all_parent;
    vector<int> temp_rank = all_rank;

    for (pii e : a_edges)
    {
        if (count_a + count == n - 1)
            break;
        int from = e.first;
        int to = e.second;

        if (find_parent(from, all_parent) == find_parent(to, all_parent) || find_parent(from, a_parent) == find_parent(to, a_parent))
            continue;
        union_set(from, to, a_parent, a_rank);
        union_set(from, to, all_parent, all_rank);
        count_a++;
    }

    for (pii e : b_edges)
    {
        if (count_b + count == n - 1)
            break;
        int from = e.first;
        int to = e.second;

        if (find_parent(from, temp_parent) == find_parent(to, temp_parent) || find_parent(from, b_parent) == find_parent(to, b_parent))
            continue;
        union_set(from, to, b_parent, b_rank);
        union_set(from, to, temp_parent, temp_rank);
        count_b++;
    }

    int p_all = find_parent(0, all_parent);
    int p_temp = find_parent(0, temp_parent);
    int p_a = find_parent(0, a_parent);
    int p_b = find_parent(0, b_parent);

    for (int i = 1; i < n; i++)
    {
        if (find_parent(i, a_parent) != p_a && find_parent(i, all_parent) != p_all)
            return -1;
        if (find_parent(i, b_parent) != p_b && find_parent(i, temp_parent) != p_temp)
            return -1;
    }
    return len - count - count_a - count_b;
}

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        return maximum(n, edges);
    }
};