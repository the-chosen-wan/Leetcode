#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

ll ans(string s)
{
    int n = s.size();
    vector<int> zero(n, 0);
    vector<int> one(n, 0);

    vector<ll> zero_one(n, 0);
    vector<ll> one_zero(n, 0);

    if (s[0] == '0')
        zero[0] = 1;
    else
        one[0] = 1;

    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '0')
        {
            ans += zero_one[i - 1];
            zero[i] = 1 + zero[i - 1];
            one[i] = one[i - 1];
            one_zero[i] = one_zero[i - 1] + one[i - 1];
            zero_one[i] = zero_one[i - 1];
        }
        else
        {
            ans += one_zero[i - 1];
            one[i] = 1 + one[i - 1];
            zero[i] = zero[i - 1];
            zero_one[i] = zero_one[i - 1] + zero[i - 1];
            one_zero[i] = one_zero[i - 1];
        }
    }
    return ans;
}

class Solution
{
public:
    long long numberOfWays(string s)
    {
        return ans(s);
    }
};