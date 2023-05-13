#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

vector<int> ans(vector<int> &nums, vector<vector<int>> &ops)
{
    int n = nums.size();
    map<int, int> m;
    for (int i = 0; i < n; i++)
        m[nums[i]] = i;

    for (vector<int> &v : ops)
    {
        int val = m[v[0]];
        m.erase(v[0]);
        m[v[1]] = val;
    }

    vector<int> ans(n);
    for (auto i : m)
    {
        ans[i.second] = i.first;
    }
    return ans;
}

class Solution
{
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
    {
        return ans(nums, operations);
    }
};