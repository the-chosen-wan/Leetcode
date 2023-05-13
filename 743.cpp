#include <iostream>
#include <bits/stdc++.h>
#define inf (int)(1e9)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define pb push_back

void dj(vector<vector<pii>> &adj, vector<int> &mindist, int source)
{
    mindist[source] = 0;
    set<pii> s;
    s.insert(make_pair(0, source));
    while (!s.empty())
    {
        pii q = *s.begin();
        s.erase(*s.begin());
        for (pii temp : adj[q.second])
        {
            if ((mindist[q.second] + temp.first) < mindist[temp.second])
            {
                s.erase(make_pair(mindist[temp.second], temp.second));
                mindist[temp.second] = mindist[q.second] + temp.first;
                s.insert(make_pair(mindist[temp.second], temp.second));
            }
        }
    }
}

int ans(vector<vector<int>> &times, int n, int k)
{
    k--;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < times.size(); i++)
    {
        times[i][0]--;
        times[i][1]--;
        adj[times[i][0]].pb(mp(times[i][2], times[i][1]));
    }

    int maxi = -inf;
    vector<int> mindist(n, inf);
    dj(adj, mindist, k);
    for (int j : mindist)
        maxi = max(j, maxi);
    if (maxi == inf)
        return -1;
    return maxi;
}

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        return ans(times, n, k);
    }
};