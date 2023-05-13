#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int total(string s)
{
    int prev[26];
    for (int i = 0; i < 26; i++)
        prev[i] = -1;

    int val[26];
    for (int i = 0; i < 26; i++)
        val[i] = 0;

    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int c = s[i] - 'A';
        for (int j = 0; j < 26; j++)
        {
            if (j == c)
            {
                sum += (i - prev[j]);
                val[j] = i - prev[j];
            }
            else
                sum += val[j];
        }
        prev[c] = i;
    }
    return sum;
}

class Solution
{
public:
    int uniqueLetterString(string s)
    {
        return (int)(total(s));
    }
};