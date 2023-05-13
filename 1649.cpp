#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair
#pragma GCC optimize("Ofast")

int ans(vector<int> &nums)
{
    ll cost = 0;
    vector<int> count((1e5) + 1, 0);
    ordered_set s;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        count[nums[i]]++;
        int less = s.order_of_key(nums[i]);
        int greater = s.size() - s.order_of_key(nums[i] + 1);
        cost = (cost + min(less, greater)) % inf;
        s.insert(nums[i]);
    }
    return cost;
}

class Solution
{
public:
    int createSortedArray(vector<int> &instructions)
    {
        return ans(instructions);
    }
};