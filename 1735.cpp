#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll inf = (1e9) + 7;
#define pb push_back
#define mp make_pair
#define M 10100
#define N 10001

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

vector<int> ans(vector<vector<int>> &queries)
{
    vector<vector<pii>> prim_pow(N);
    vector<bool> isprime(N, true);
    prim_pow[1] = {mp(1, 0)};

    for (int i = 2; i < N; i++)
    {
        if (isprime[i])
        {
            for (int j = i; j < N; j += i)
            {
                isprime[j] = false;
                int c = 0;
                int temp = j;
                while (temp % i == 0)
                {
                    c++;
                    temp /= i;
                }
                prim_pow[j].pb(mp(i, c));
            }
        }
    }

    vector<ll> fact(M, 1);
    for (int i = 1; i < M; i++)
        fact[i] = (fact[i - 1] * i) % inf;
    vector<ll> invfact(M, 1);
    for (int i = 1; i < M; i++)
        invfact[i] = inverse(fact[i]);

    auto query = [&](int ni, int ki) -> int
    {
        ll ret = 1;
        for (pii &e : prim_pow[ki])
        {
            ret = (((ret * fact[ni + e.second - 1]) % inf * invfact[ni - 1]) % inf * invfact[e.second]) % inf;
        }
        return (int)ret;
    };

    vector<int> ans;
    for (vector<int> &q : queries)
    {
        ans.pb(query(q[0], q[1]));
    }
    return ans;
}

class Solution
{
public:
    vector<int> waysToFillArray(vector<vector<int>> &queries)
    {
        return ans(queries);
    }
};