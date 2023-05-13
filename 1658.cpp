#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int mini(vector<int> &nums, int x)
{
    int sum = 0;
    for (int k : nums)
        sum += k;

    int n = nums.size();
    int len = -1;
    sum = sum - x;

    if (sum == 0)
        return n;

    int pref = 0;
    unordered_map<int, int> mapa;
    mapa[0] = -1;

    for (int i = 0; i < n; i++)
    {
        pref += nums[i];
        if (mapa.find(pref - sum) != mapa.end())
            len = max(len, i - mapa[pref - sum]);
        if (mapa.find(pref) == mapa.end())
            mapa[pref] = i;
    }
    if (len == -1)
        return -1;
    return n - len;
}

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        return mini(nums, x);
    }
};