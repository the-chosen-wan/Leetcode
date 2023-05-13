#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e7;
#define pb push_back
#define mp make_pair

ll gcd(ll x, ll y)
{
    if (y > x)
        swap(x, y);
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

ll lcm(ll x, ll y)
{
    return (x * y) / gcd(x, y);
}

vector<int> ans(vector<int> &nums)
{
    int n = nums.size();
    ll val = nums[0];
    vector<int> ans;

    for (int i = 1; i < n; i++)
    {
        if (gcd(val, nums[i]) > 1)
            val = lcm(val, nums[i]);
        else
        {
            ans.pb((int)val);
            val = nums[i];
        }
    }
    ans.pb(val);
    return ans;
}

class Solution
{
public:
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        return ans(nums);
    }
};