#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
#define N 70

bool check(vector<int> &n1, vector<int> &n2)
{
    for (int i = 0; i < N; i++)
        if (n1[i] != n2[i])
            return false;
    return true;
}

string ans(string s, string t)
{
    vector<int> tc(N, 0);
    vector<int> sc(N, 0);

    int tn = t.size();
    int sn = s.size();
    for (int i = 0; i < tn; i++)
        tc[t[i] - 'A']++;

    int low = 0;
    int maxlen = inf;
    string ans = "";
    for (int i = 0; i < sn; i++)
    {
        sc[s[i] - 'A']++;
        while (low <= i && !check(sc, tc))
        {
            sc[s[low] - 'A']--;
            low++;
        }

        if (low > i)
        {
            sc[s[i] - 'A']++;
            low = i;
            continue;
        }
        if (i - low + 1 < maxlen)
        {
            maxlen = i - low + 1;
            ans = s.substr(low, i - low + 1);
        }
    }
    return ans;
}

class Solution
{
public:
    string minWindow(string s, string t)
    {
        return ans(s, t);
    }
};