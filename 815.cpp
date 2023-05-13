#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
#define N ((1e5) + 1)
#define M 502

int ans(vector<vector<int>> &routes, int src, int target)
{
    int n = routes.size();
    if (src == target)
        return 0;
    vector<vector<int>> adj(N + n + 1);
    unordered_set<int> s_set, t_set;

    for (int i = 0; i < n; i++)
    {
        int s = routes[i].size();
        for (int j = 0; j < s; j++)
        {
            adj[routes[i][j]].pb(N + i);
            adj[N + i].pb(routes[i][j]);
            if (routes[i][j] == src)
                s_set.insert(i);
            if (routes[i][j] == target)
                t_set.insert(i);
        }
    }

    for (int i : s_set)
        adj[N + n].pb(N + i);

    vector<int> mindist(N + n + 1, inf);
    mindist[N + n] = 0;
    queue<int> q;
    q.push(N + n);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int v : adj[front])
        {
            if (mindist[v] == inf)
            {
                q.push(v);
                mindist[v] = mindist[front] + 1;
            }
        }
    }

    int maxa = inf;
    for (int i : t_set)
        maxa = min(maxa, mindist[i + N]);
    if (maxa == inf)
        return -1;
    return 1 + ((maxa - 1) / 2);
}

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        return ans(routes, source, target);
    }
};
