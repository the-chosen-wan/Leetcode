#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
#define MAXN ((1 << 16) - 1)

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int ans(int n)
{
    vector<int> nums;
    vector<int> two, three, five;
    nums.pb(1);
    nums.pb(2);
    nums.pb(3);
    nums.pb(5);
    ll ntwo = 2;
    ll nthree = 3;
    ll nfive = 5;

    while (ntwo <= MAXN)
    {
        two.pb(ntwo);
        ntwo *= 2;
    }

    while (nthree <= MAXN)
    {
        three.pb(nthree);
        nthree *= 3;
    }

    while (nfive <= MAXN)
    {
        five.pb(nfive);
        nfive *= 5;
    }

    int stwo = two.size();
    int sthree = three.size();
    int sfive = five.size();

    for (int i = 0; i < stwo; i++)
        for (int j = 0; j < sthree; j++)
            for (int k = 0; k < sfive; k++)
            {
                ll ret = (ll)two[i] * (ll)three[j] * (ll)five[k];
                if (ret <= MAXN)
                    nums.pb((int)ret);
            }
    sort(nums.begin(), nums.end());
    return nums[n - 1];
}

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        return ans(n);
    }
};