#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int traverse(vector<vector<int>> &dp, unordered_map<int, int> &s, vector<int> &nums, int ind, int jump)
{
    if (ind == nums.size() - 1)
    {
        dp[ind][jump] = 1;
        return dp[ind][jump];
    }
    if (dp[ind][jump] != -1)
        return dp[ind][jump];

    int val1 = -1;
    int val2 = -1;
    int val3 = -1;
    if (s.find(nums[ind] + jump) != s.end())
        val1 = traverse(dp, s, nums, s[nums[ind] + jump], jump);
    if (s.find(nums[ind] + jump - 1) != s.end() && jump != 1)
        val2 = traverse(dp, s, nums, s[nums[ind] + jump - 1], jump - 1);
    if (s.find(nums[ind] + jump + 1) != s.end())
        val3 = traverse(dp, s, nums, s[nums[ind] + jump + 1], jump + 1);

    if (val1 == 1 || val2 == 1 || val3 == 1)
        dp[ind][jump] = 1;
    else
        dp[ind][jump] = 0;
    return dp[ind][jump];
}

bool ans(vector<int> &stones)
{
    int n = stones.size();
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        m[stones[i]] = i;

    if (stones[1] != 1)
        return false;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return traverse(dp, m, stones, 1, 1);
    // int ret = 0;
    // for(int i=0;i<n;i++){
    //     if(dp[n-1][i]==1)
    //         {ret=1;break;}
    // }
    // return ret;
}
class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        return ans(stones);
    }
};