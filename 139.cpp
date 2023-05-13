#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool ans(string s, vector<string> &dict)
{
    unordered_set<string> m(dict.begin(), dict.end());

    string temp = "";
    int n = s.size();
    vector<bool> check(n, false);

    for (int i = 0; i < n; i++)
    {
        temp.pb(s[i]);
        if (m.find(temp) != m.end())
            check[i] = true;
    }

    for (int i = 0; i < n; i++)
    {
        string temp = "";
        if (!check[i])
            continue;
        for (int j = i + 1; j < min(i + 21, n); j++)
        {
            temp.pb(s[j]);
            if (m.find(temp) != m.end())
                check[j] = true;
        }
    }

    return check[n - 1];
}

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        return ans(s, wordDict);
    }
};