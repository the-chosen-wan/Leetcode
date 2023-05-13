#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define inf (ll)((1e9) + 7)
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

ll inverse(ll a)
{
    return binpow(a, inf - 2);
}

int count(int n)
{
    vector<ll> fact(2 * n + 1);

    fact[0] = 1;
    for (int i = 1; i <= 2 * n; i++)
        fact[i] = (fact[i - 1] * i) % inf;

    return (fact[2 * n] * inverse(binpow(2, n))) % inf;
}

class Solution
{
public:
    int countOrders(int n)
    {
        return count(n);
    }
};