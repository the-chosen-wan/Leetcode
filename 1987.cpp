#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair
#define N ((1e5) + 1)

int ans(string s)
{
    int n = s.length();
    ll val0 = 0;
    ll val1 = 0;
    ll sum = 0;
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            sum = (sum + val1) % inf;
            val0 = (val0 + val1) % inf;
            c++;
        }
        if (s[i] == '1')
        {
            sum = (sum + val0 + 1) % inf;
            val1 = (val1 + val0 + 1) % inf;
        }
    }

    if (c)
        sum = (sum + 1) % inf;
    return sum;
}

class Solution
{
public:
    int numberOfUniqueGoodSubsequences(string binary)
    {
        return ans(binary);
    }
};