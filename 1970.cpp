#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

void initialize(int vertices, vector<int> &parent, vector<int> &rank1)
{
    parent.resize(vertices);
    rank1.resize(vertices);
    for (int i = 0; i < vertices; i++)
    {
        parent[i] = i;
        rank1[i] = 0;
    }
}
int find_parent(int v, vector<int> &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_parent(parent[v], parent);
}
void union_set(int v1, int v2, vector<int> &parent, vector<int> &rank1)
{
    v1 = find_parent(v1, parent);
    v2 = find_parent(v2, parent);
    if (rank1[v1] < rank1[v2])
        parent[v1] = v2;
    else if (rank1[v1] > rank1[v2])
        parent[v2] = v1;
    else
    {
        parent[v1] = v2;
        rank1[v2]++;
    }
}

int latest(int row, int col, vector<vector<int>> &grid)
{
    int n = (row * col) + 2;
    vector<bool> visited(n, false);
    vector<int> parent;
    vector<int> rank;

    initialize(n, parent, rank);
    for (int i = 1; i <= col; i++)
    {
        union_set(0, i, parent, rank);
        union_set(n - 1, (row - 1) * col + i, parent, rank);
    }
    int first = -1;

    for (int i = grid.size() - 1; i >= 0; i--)
    {
        int r = --grid[i][0];
        int c = grid[i][1];
        int val = r * col + c;
        visited[val] = true;

        int val1 = (r - 1) * col + c;
        int val2 = (r + 1) * col + c;
        int val3 = r * col + c - 1;
        int val4 = r * col + c + 1;

        if (r != 0 && visited[val1])
            union_set(val, val1, parent, rank);
        if (r != row - 1 && visited[val2])
            union_set(val, val2, parent, rank);
        if (c != 1 && visited[val3])
            union_set(val, val3, parent, rank);
        if (c != col && visited[val4])
            union_set(val, val4, parent, rank);

        if (find_parent(0, parent) == find_parent(n - 1, parent))
        {
            first = i;
            break;
        }
    }
    return first;
}

class Solution
{
public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        return latest(row, col, cells);
    }
};