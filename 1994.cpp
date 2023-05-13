#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

ll binpow(ll a, ll b)
{
    ll ret = 1;
    while (b > 0)
    {
        if (b & 1)
            ret = (ret * a) % inf;
        a = (a * a) % inf;
        b >>= 1;
    }
    return ret;
}

int ans(vector<int> &nums)
{
    int n = nums.size();
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    unordered_set<ll> valid;

    int s = primes.size();
    for (int i = 0; i < (1 << s); i++)
    {
        ll p = 1;
        for (int j = 0; j < s; j++)
        {
            if ((i & (1 << j)) != 0)
                p *= primes[j];
        }
        valid.insert(p);
    }

    int cnt = 0;
    int one_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (valid.find(nums[i]) != valid.end())
            cnt++;
        if (nums[i] == 1)
            one_cnt++;
    }

    ll ret = (binpow(2, cnt) - binpow(2, one_cnt) + inf) % inf;
    return ret;
}

class Solution
{
public:
    int numberOfGoodSubsets(vector<int> &nums)
    {
        return ans(nums);
    }
};