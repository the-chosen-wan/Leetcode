#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int mini(vector<int> &nums, int k)
{
    int n = nums.size();
    int c = 0;
    sort(nums.begin(), nums.end());

    int pos = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] - nums[pos] <= k)
            continue;
        c++;
        pos = i;
    }
    c++;

    return c;
}

class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        return mini(nums, k);
    }
};