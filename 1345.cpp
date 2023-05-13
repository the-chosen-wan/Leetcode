#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int jump(vector<int> &arr)
{
    int n = arr.size();
    int c_unique = 0;

    map<int, int> mappa;
    for (int i = 0; i < n; i++)
    {
        if (mappa.find(arr[i]) == mappa.end())
        {
            mappa[arr[i]] = n + c_unique;
            c_unique++;
        }
    }

    vector<vector<pii>> adj;
    adj.resize(n + c_unique);

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            adj[0].pb(mp(1, 1));
            adj[0].pb(mp(1, mappa[arr[0]]));
            adj[mappa[arr[0]]].pb(mp(0, 0));
        }

        else if (i == n - 1)
        {
            adj[n - 1].pb(mp(1, n - 2));
            adj[n - 1].pb(mp(1, mappa[arr[n - 1]]));
            adj[mappa[arr[n - 1]]].pb(mp(0, n - 1));
        }

        else
        {
            adj[i].pb(mp(1, i - 1));
            adj[i].pb(mp(1, i + 1));
            adj[mappa[arr[i]]].pb(mp(0, i));
            adj[i].pb(mp(1, mappa[arr[i]]));
        }
    }

    vector<int> d(n + c_unique, inf);
    d[0] = 0;
    deque<int> q;
    q.push_front(0);

    while (!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for (pii edge : adj[v])
        {
            int w = edge.first;
            int to = edge.second;
            if (d[v] + w < d[to])
            {
                d[to] = d[v] + w;
                if (w == 0)
                    q.push_front(to);
                else
                    q.push_back(to);
            }
        }
    }

    return d[n - 1];
}

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        return jump(arr);
    }
};