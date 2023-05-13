#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define N ((1e5) + 1)
#define pb push_back
#define mp make_pair

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

int ans(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end(), greater<int>());
    vector<int> counter(N, 0);
    ll tot = 0;
    ordered_set s;
    int prevsum = 0;
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        ll prefsum = 0;
        ll mult = 0;
        ll currsum = 0;
        if (counter[nums[i]] != 0)
        {
            s.insert(nums[i]);
            c++;
            tot += prevsum;
            continue;
        }
        tot += c * c;
        c = 0;
        counter[nums[i]]++;
        for (int j = nums[i]; j <= N; j += nums[i])
        {
            int count = s.order_of_key(j);
            int temp = count - prefsum;
            // if(count==0)
            //     break;
            currsum += (mult * temp);
            prefsum = count;
            mult++;
        }
        c++;
        s.insert(nums[i]);
        prevsum = currsum;
        tot += currsum;
    }
    tot += c * c;
    return tot;
}
class Solution
{
public:
    int sumOfFlooredPairs(vector<int> &nums)
    {
        return ans(nums);
    }
};