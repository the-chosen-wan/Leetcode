#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

vector<int> ans(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> pref(n);
    pref[0] = 1;

    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] < nums[i])
            pref[i] = 1;
        else
            pref[i] = pref[i - 1] + 1;
    }

    vector<int> suff(n);
    suff[n - 1] = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i + 1] < nums[i])
            suff[i] = 1;
        else
            suff[i] = suff[i + 1] + 1;
    }

    vector<int> ans;
    for (int i = 1; i < n - 1; i++)
    {
        if (suff[i + 1] >= k && pref[i - 1] >= k)
            ans.pb(i);
    }

    return ans;
}

class Solution
{
public:
    vector<int> goodIndices(vector<int> &nums, int k)
    {
        return ans(nums, k);
    }
};