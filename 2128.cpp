#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

bool check(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 1; i < n; i++)
    {
        int val = grid[i][0];
        for (int j = 0; j < m; j++)
            if (grid[i][j] != val)
                return false;
    }
    return true;
}

void flip(vector<vector<int>> &grid, int col)
{
    int n = grid.size();
    for (int i = 0; i < n; i++)
        grid[i][col] = 1 - grid[i][col];
    return;
}

bool ans(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int first = grid[0][0];

    if (m == 1)
    {
        return true;
    }

    if (n == 1)
    {
        return true;
    }

    vector<vector<int>> grid1(grid);

    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] == 0)
            flip(grid, i);
    }

    for (int i = 0; i < m; i++)
    {
        if (grid1[0][i] == 1)
            flip(grid1, i);
    }

    bool ch1 = check(grid);
    bool ch2 = check(grid1);

    if (ch1 || ch2)
        return true;
    return false;
}

class Solution
{
public:
    bool removeOnes(vector<vector<int>> &grid)
    {
        return ans(grid);
    }
};