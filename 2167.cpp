#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e7;
#define pb push_back
#define mp make_pair

int ans(string s)
{
    int n = s.size();
    vector<int> suff(n, 0);
    vector<int> pref(n, 0);

    if (s[n - 1] == '1')
        suff[n - 1] = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == '0')
            suff[i] = suff[i + 1];
        else
            suff[i] = min(suff[i + 1] + 2, n - i);
    }

    if (s[0] == '1')
        pref[0] = 1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == '0')
            pref[i] = pref[i - 1];
        else
            pref[i] = min(pref[i - 1] + 2, i + 1);
    }

    int ans = inf;
    for (int i = 0; i < n - 1; i++)
        ans = min(ans, pref[i] + suff[i + 1]);
    ans = min({ans, pref[n - 1], suff[0]});
    return ans;
}

class Solution
{
public:
    int minimumTime(string s)
    {
        return ans(s);
    }
};