#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define pb push_back
const int inf = (int)1e9;

bool ans(vector<vector<int>> &grid, int val)
{
    int n = grid.size();
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(grid[i].begin(), grid[i].end(), val);
        if (it != grid[i].end() && *it == val)
            return true;
    }
    return false;
}

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        return ans(matrix, target);
    }
};