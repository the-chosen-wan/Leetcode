#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
#define N 30

struct trie
{
    trie *vec[2];
    int count;

    trie()
    {
        vec[0] = nullptr;
        vec[1] = nullptr;
        count = 0;
    }
};

void insert(trie *t, int num, int pos)
{
    t->count++;
    if (pos == -1)
        return;
    int ind = (num & (1 << pos)) != 0 ? 1 : 0;
    if (t->vec[ind] == nullptr)
        t->vec[ind] = new trie();
    insert(t->vec[ind], num, pos - 1);
    return;
}

bool erase(trie *t, int num, int pos)
{
    t->count--;
    if (pos == -1)
    {
        if (t->count == 0)
        {
            delete (t);
            return true;
        }
        return false;
    }
    int ind = (num & (1 << pos)) != 0 ? 1 : 0;
    bool chk = erase(t->vec[ind], num, pos - 1);
    if (chk)
        t->vec[ind] = nullptr;
    if (t->count == 0)
    {
        delete (t);
        return true;
    }
    return false;
}

int maxxor(trie *t, int num, int pos)
{
    if (pos == -1)
        return 0;
    int ind = (num & (1 << pos)) != 0 ? 1 : 0;
    if (ind == 1)
    {
        if (t->vec[0] != nullptr)
            return (1 << pos) + maxxor(t->vec[0], num, pos - 1);
        if (t->vec[1] != nullptr)
            return maxxor(t->vec[1], num, pos - 1);
    }
    else
    {
        if (t->vec[1] != nullptr)
            return (1 << pos) + maxxor(t->vec[1], num, pos - 1);
        if (t->vec[0] != nullptr)
            return maxxor(t->vec[0], num, pos - 1);
    }
    return 0;
}

vector<int> ans(vector<int> &parents, vector<vector<int>> &queries)
{
    int n = parents.size();
    int q = queries.size();

    vector<vector<int>> adj(n);
    int root = 0;

    for (int i = 0; i < n; i++)
    {
        if (parents[i] == -1)
        {
            root = i;
            continue;
        }
        adj[i].pb(parents[i]);
        adj[parents[i]].pb(i);
    }

    vector<vector<pii>> qs(n);
    for (int i = 0; i < q; i++)
        qs[queries[i][0]].pb(mp(i, queries[i][1]));

    vector<int> ans(q);
    trie *t = new trie();

    auto dfs = [&](int src, int p, auto &&dfs) -> void
    {
        insert(t, src, N);
        for (pii &e : qs[src])
        {
            ans[e.first] = maxxor(t, e.second, N);
        }

        for (int v : adj[src])
        {
            if (v != p)
                dfs(v, src, dfs);
        }
        erase(t, src, N);
        return;
    };
    dfs(root, root, dfs);
    return ans;
}

class Solution
{
public:
    vector<int> maxGeneticDifference(vector<int> &parents, vector<vector<int>> &queries)
    {
        return ans(parents, queries);
    }
};