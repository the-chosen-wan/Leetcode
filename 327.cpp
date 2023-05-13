#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ll = long long;
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums, int lower, int upper)
{
    int n = nums.size();
    ordered_set s;

    ll sum = 0;
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum >= lower && sum <= upper)
            c++;

        if (!s.empty())
        {
            int n1 = s.order_of_key(sum - lower + 1);
            int n2 = s.order_of_key(sum - upper);
            c += (n1 - n2);
        }
        s.insert(sum);
    }
    return c;
}

class Solution
{
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        return ans(nums, lower, upper);
    }
};
