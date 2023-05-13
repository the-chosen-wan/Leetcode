#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define pb push_back
const int inf = (int)1e9;

vector<int> can(int n, vector<vector<int>> &courses)
{
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    int m = courses.size();

    for (int i = 0; i < m; i++)
    {
        adj[courses[i][0]].pb(courses[i][1]);
        indeg[courses[i][1]]++;
    }

    vector<int> vis;
    vector<int> visited(n, 0);
    bool cycle = false;

    auto dfs = [&](int src, auto &&dfs) -> void
    {
        visited[src] = 1;
        for (int v : adj[src])
        {
            if (visited[v] == 1)
                cycle = true;
            if (!visited[v])
                dfs(v, dfs);
        }
        visited[src] = 2;
        vis.pb(src);
        return;
    };

    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            dfs(i, dfs);
        if (cycle)
            return {};
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, dfs);
        if (cycle)
            return {};
    }
    return vis;
}

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        return can(numCourses, prerequisites);
    }
};