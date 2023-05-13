
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % inf;
        a = (a * a) % inf;
        b >>= 1;
    }
    return res;
}

int ans(int k)
{
    if (k == 1)
        return 1;
    ll val = k / 3;
    if (k % 3 == 0)
        return binpow(3, val);
    else if (k % 3 == 2)
        return (2 * binpow(3, val)) % inf;
    else
        return (4 * binpow(3, val - 1)) % inf;
}
class Solution
{
public:
    int maxNiceDivisors(int primeFactors)
    {
        return ans(primeFactors);
    }
};