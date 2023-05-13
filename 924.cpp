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

int find_set(int v, vector<int> &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &size)
{
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int ans(vector<vector<int>> &graph, vector<int> &initial)
{
    int n = graph.size();
    vector<pii> adj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1 && i != j)
                adj.pb(mp(i, j));
        }
    }

    vector<int> parent, size, infect(n, -1);
    initialize(n, parent, size);

    for (int i : initial)
        infect[i] = i;

    int total = 0;
    for (pii e : adj)
    {
        int p1 = find_set(e.first, parent);
        int p2 = find_set(e.second, parent);
        if (p1 == p2)
            continue;
        union_sets(e.first, e.second, parent, size);
        int p3 = find_set(e.first, parent);
        if (infect[p1] == n || infect[p2] == n)
            infect[p3] == n;
        else if (infect[p1] >= 0 && infect[p2] >= 0)
            infect[p3] = n;
        else if (infect[p1] == -1 && infect[p2] == -1)
            infect[p3] = -1;
        else if (infect[p1] == -1)
            infect[p3] = infect[p2];
        else if (infect[p2] == -1)
            infect[p3] = infect[p1];
    }

    for (int i = 0; i < n; i++)
    {
        if (i == find_set(i, parent) && infect[i] != -1)
            total += size[i];
    }

    sort(initial.begin(), initial.end());
    int maxa = -inf;
    int pos = -1;

    for (int i : initial)
    {
        int temp;
        int par = find_set(i, parent);
        if (infect[par] == i)
            temp = size[par];
        else
            temp = 0;
        if (temp > maxa)
        {
            maxa = temp;
            pos = i;
        }
    }
    return pos;
}

class Solution
{
public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial)
    {
        return ans(graph, initial);
    }
};