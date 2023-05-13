#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define pf push_front
#define mp make_pair

string ans(string s)
{
    int n = s.size();
    stack<int> sp;
    string ans = "";
    vector<bool> valid(n, false);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
        {
            if (!sp.empty())
            {
                valid[sp.top()] = true;
                valid[i] = true;
                sp.pop();
            }
        }
        else if (s[i] == '(')
            sp.push(i);
        else
            valid[i] = true;
    }

    for (int i = 0; i < n; i++)
    {
        if (valid[i])
            ans.pb(s[i]);
    }
    return ans;
}

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        return ans(s);
    }
};
