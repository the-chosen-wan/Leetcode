#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define pf push_front
#define mp make_pair

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
    int c = 0;

    vector<int> parent, size;
    initialize(n * m, parent, size);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val = i * m + j;
            int val1 = (i + 1) * m + j;
            int val2 = i * m + j + 1;
            if (grid[i][j] == 1)
            {
                c++;
                if (i + 1 < n && grid[i + 1][j] == 1)
                    union_sets(val, val1, parent, size);
                if (j + 1 < m && grid[i][j + 1] == 1)
                    union_sets(val, val2, parent, size);
            }
        }
    }
    if (c == 0)
        return c;
    return *max_element(size.begin(), size.end());
}

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        return ans(grid);
    }
};