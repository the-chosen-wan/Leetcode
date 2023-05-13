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

int ans(vector<int> &vals, vector<vector<int>> &edges)
{
    int n = vals.size();
    vector<int> parent, size;
    initialize(n, parent, size);

    vector<vector<int>> adj(n);
    unordered_map<int, vector<int>> mappa;

    for (vector<int> &e : edges)
    {
        if (vals[e[0]] <= vals[e[1]])
            adj[e[1]].pb(e[0]);
        if (vals[e[1]] <= vals[e[0]])
            adj[e[0]].pb(e[1]);
    }

    for (int i = 0; i < n; i++)
    {
        if (mappa.find(vals[i]) == mappa.end())
            mappa[vals[i]] = {};
        mappa[vals[i]].pb(i);
    }

    unordered_set<int> temp(vals.begin(), vals.end());
    vals = vector<int>(temp.begin(), temp.end());
    sort(vals.begin(), vals.end());
    int n1 = vals.size();
    int ans = 0;

    for (int i = 0; i < n1; i++)
    {
        unordered_map<int, int> leaders;

        for (int j : mappa[vals[i]])
        {
            for (int k : adj[j])
                union_sets(j, k, parent, size);
        }

        for (int j : mappa[vals[i]])
            leaders[find_sets(j, parent)]++;

        for (pii e : leaders)
        {
            ans += (e.second * (e.second - 1)) / 2;
        }
    }
    ans += n;
    return ans;
}

class Solution
{
public:
    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
    {
        return ans(vals, edges);
    }
};