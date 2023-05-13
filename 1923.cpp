#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

int ans(int n, vector<vector<int>> &paths)
{
    map<pii, int> m;
    int s = paths.size();
    vector<int> count(n, 0);
    vector<int> tin(n, 0);
    int c = 0;

    for (int i = 0; i < s; i++)
    {
        int n = paths[i].size();
        for (int j = 0; j < n - 1; j++)
        {
            if (m.find(mp(paths[i][j], paths[i][j + 1])) == m.end())
                m[mp(paths[i][j], paths[i][j + 1])] = 1;
            else
                m[mp(paths[i][j], paths[i][j + 1])]++;
            count[paths[i][j]]++;
        }
        count[paths[i][paths[i].size() - 1]]++;
    }

    vector<vector<int>> adj(n);
    vector<int> minpath(n, -1);
    vector<int> valid;
    for (auto e : m)
    {
        if (e.second == s)
        {
            adj[e.first.first].pb(e.first.second);
        }
    }

    for (int i = 0; i < n; i++)
        if (count[i] == s)
            valid.pb(i);

    int maxa = 0;
    auto dfs = [&](int src, auto &&dfs) -> int
    {
        if (minpath[src] != -1)
            return minpath[src];
        c++;
        tin[src] = c;
        minpath[src] = -2;
        for (int v : adj[src])
        {
            if (minpath[v] != -2)
                minpath[src] += dfs(v, dfs);
            else
                maxa = max(tin[src] - tin[v] + 2, maxa);
        };
        minpath[src] += 3;
        maxa = max(maxa, minpath[src]);
        c--;
        return minpath[src];
    };

    for (int i : valid)
        if (minpath[i] == -1)
            dfs(i, dfs);
    return maxa;
}

class Solution
{
public:
    int longestCommonSubpath(int n, vector<vector<int>> &paths)
    {
        return ans(n, paths);
    }
};