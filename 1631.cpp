#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

struct triple
{
    int w;
    int from;
    int to;
    triple(int w, int from, int to)
    {
        this->w = w;
        this->to = to;
        this->from = from;
    }

    bool operator<(const triple &t) const
    {
        if (w != t.w)
            return w < t.w;
        else if (from != t.from)
            return from < t.from;
        else
            return to < t.to;
    }
};

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

int ans(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> parent, size;
    initialize(n * m, parent, size);
    vector<triple> edges;

    auto abs = [](int x) -> int
    {
        return x > 0 ? x : -x;
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val = i * m + j;
            int val1 = (i + 1) * m + j;
            int val2 = i * m + j + 1;

            if (i + 1 < n)
                edges.pb(triple(abs(grid[i][j] - grid[i + 1][j]), val, val1));
            if (j + 1 < m)
                edges.pb(triple(abs(grid[i][j] - grid[i][j + 1]), val, val2));
        }
    }

    sort(edges.begin(), edges.end());
    int s = edges.size();
    for (int i = 0; i < s; i++)
    {
        union_sets(edges[i].to, edges[i].from, parent, size);
        if (find_sets(0, parent) == find_sets(n * m - 1, parent))
            return edges[i].w;
    }
    return 0;
}

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        return ans(heights);
    }
};