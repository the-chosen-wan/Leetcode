#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
const int p = 31;
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

ll ret(int i, int j, vector<ll> &hash)
{
    if (i == 0)
        return hash[j];
    return ((hash[j] - hash[i - 1]) * inverse(binpow(p, i))) % inf;
}

int ans(string s)
{
    int n = s.size();
    vector<ll> pow(n);
    pow[0] = 1;
    for (int i = 1; i < n; i++)
        pow[i] = (pow[i - 1] * p) % inf;

    vector<ll> hash(n, 0);
    hash[0] = s[0];
    for (int i = 1; i < n; i++)
        hash[i] = (hash[i - 1] + (s[i] - 'a') * pow[i]) % inf;

    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (2 * j - 1 >= i)
                if (ret(2 * j - i - 1, j - 1, hash) == ret(j, i, hash))
                    c++;
        }
    }
    return c;
}

class Solution
{
public:
    int distinctEchoSubstrings(string text)
    {
        return ans(text);
    }
};