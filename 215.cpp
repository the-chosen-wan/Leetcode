#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair
#define N ((1e5) + 1)

int ans(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[k - 1];
}

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return ans(nums, k);
    }
};