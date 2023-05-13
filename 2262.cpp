#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

ll total(string s)
{
    int prev[26];
    for (int i = 0; i < 26; i++)
        prev[i] = -1;

    ll sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int c = s[i] - 'a';
        prev[c] = i;
        for (int j = 0; j < 26; j++)
        {
            if (prev[j] != -1)
            {
                sum += (prev[j] + 1);
            }
        }
    }
    return sum;
}

class Solution
{
public:
    long long appealSum(string s)
    {
        return total(s);
    }
};