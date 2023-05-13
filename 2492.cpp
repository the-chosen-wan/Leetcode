#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

int ans(int n, vector<vector<int>> &node)
{
    vector<vector<pii>> adj(n);
    int m = node.size();

    for (int i = 0; i < m; i++)
    {
        int from = node[i][0] - 1;
        int to = node[i][1] - 1;
        int cost = node[i][2];

        adj[from].pb(mp(to, cost));
        adj[to].pb(mp(from, cost));
    }

    vector<bool> visited(n, false);
    queue<int> q;

    visited[0] = true;
    q.push(0);
    int ret = inf;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (pii e : adj[front])
        {
            ret = min(ret, e.second);
            if (!visited[e.first])
            {
                q.push(e.first);
                visited[e.first] = true;
            }
        }
    }

    return ret;
}

class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        return ans(n, roads);
    }
};