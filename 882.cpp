#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

int ans(vector<vector<int>> &edges, int moves, int n)
{
    vector<vector<pii>> adj(n);
    int m = edges.size();
    for (int i = 0; i < m; i++)
    {
        edges[i][2]++;
        adj[edges[i][0]].pb(mp(edges[i][2], edges[i][1]));
        adj[edges[i][1]].pb(mp(edges[i][2], edges[i][0]));
    }

    vector<int> mindist(n, inf);
    set<pii> s;
    s.insert(mp(0, 0));

    while (!s.empty())
    {
        pii top = *s.begin();
        s.erase(top);
        mindist[top.second] = top.first;
        for (pii &v : adj[top.second])
        {
            if (mindist[top.second] + v.first < mindist[v.second])
            {
                s.erase(mp(mindist[v.second], v.second));
                mindist[v.second] = mindist[top.second] + v.first;
                s.insert(mp(mindist[v.second], v.second));
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (pii e : adj[i])
        {
            e.first--;
            int min2 = mindist[e.second];
            int len = min(e.first, max(0, moves - mindist[i]));
            cnt += (len);
            if (min2 <= moves)
            {
                int newlen = min({e.first - len, moves - min2});
                cnt += (newlen);
            }
        }
    }
    cnt /= 2;
    for (int i = 0; i < n; i++)
        if (mindist[i] <= moves)
            cnt++;
    return cnt;
}

class Solution
{
public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
    {
        return ans(edges, maxMoves, n);
    }
};