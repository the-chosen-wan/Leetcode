#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

int ans(string s)
{
    int n = s.size();
    stack<char> sp;
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
        {
            if (sp.empty())
                c++;
            else
                sp.pop();
        }
        else
        {
            sp.push(s[i]);
        }
    }

    return c + sp.size();
}

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        return ans(s);
    }
};