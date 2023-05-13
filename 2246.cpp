#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e7;
#define pb push_back
#define mp make_pair

void dfs(int par, int src, vector<vector<int>> &adj, vector<int> &longest, string &s, int &maxa)
{
    int largest = -inf;
    int second_largest = -inf;
    longest[src] = 1;
    vector<int> temp;

    for (int v : adj[src])
    {
        if (v != par)
        {
            dfs(src, v, adj, longest, s, maxa);
            if (s[v] != s[src])
            {
                temp.pb(longest[v]);
            }
        }
    }
    sort(temp.begin(), temp.end(), greater<int>());
    if (temp.size() >= 2)
        maxa = max(maxa, 1 + temp[0] + temp[1]);
    if (temp.size() >= 1)
    {
        longest[src] = longest[src] + temp[0];
    }
    maxa = max(maxa, longest[src]);
    return;
}

int ans(vector<int> &parent, string &s)
{
    int n = parent.size();
    vector<vector<int>> adj(n);

    for (int i = 1; i < n; i++)
    {
        adj[parent[i]].pb(i);
        adj[i].pb(parent[i]);
    }

    vector<int> longest(n);
    int maxa = -inf;
    dfs(0, 0, adj, longest, s, maxa);
    return maxa;
}

class Solution
{
public:
    int longestPath(vector<int> &parent, string s)
    {
        return ans(parent, s);
    }
};