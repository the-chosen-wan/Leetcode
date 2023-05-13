#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

vector<int> counter(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    ans[n - 1] = 0;
    ordered_set s;
    s.insert(nums[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = s.order_of_key(nums[i]);
        s.insert(nums[i]);
    }
    return ans;
}

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        return counter(nums);
    }
};
