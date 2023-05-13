#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(string s)
{
    int n = s.size();
    vector<int> pref_b(n, 0);
    if (s[0] == 'b')
        pref_b[0] = 1;

    for (int i = 1; i < n; i++)
    {
        pref_b[i] = pref_b[i - 1];
        if (s[i] == 'b')
            pref_b[i]++;
    }

    vector<int> suff_a(n, 0);
    if (s[n - 1] == 'a')
        suff_a[n - 1] = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        suff_a[i] = suff_a[i + 1];
        if (s[i] == 'a')
            suff_a[i]++;
    }

    int mini = inf;
    for (int i = 0; i < n - 1; i++)
        mini = min(mini, pref_b[i] + suff_a[i + 1]);
    mini = min({mini, pref_b[n - 1], suff_a[0]});
    return mini;
}

class Solution
{
public:
    int minimumDeletions(string s)
    {
        return ans(s);
    }
};