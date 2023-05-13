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
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    if (s[0] == '*')
        dp[1] = 9;
    else
        dp[1] = 1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == '*')
        {
            dp[i + 1] = (dp[i + 1] + 9 * dp[i]) % inf;
            if (s[i - 1] == '*')
                dp[i + 1] = (dp[i + 1] + 15 * dp[i - 1]) % inf;
            else if (s[i - 1] == '1')
                dp[i + 1] = (dp[i + 1] + 9 * dp[i - 1]) % inf;
            else if (s[i - 1] == '2')
                dp[i + 1] = (dp[i + 1] + 6 * dp[i - 1]) % inf;
        }
        else
        {
            dp[i + 1] = (dp[i + 1] + dp[i]) % inf;
            if (s[i - 1] == '*')
            {
                int temp = s[i] - '0';
                if (temp <= 6)
                    dp[i + 1] = (dp[i + 1] + 2 * dp[i - 1]) % inf;
                else if (temp > 6)
                    dp[i + 1] = (dp[i + 1] + dp[i - 1]) % inf;
            }
            else
            {
                int val = s[i] - '0' + 10 * (s[i - 1] - '0');
                if (val >= 10 && val <= 26)
                    dp[i + 1] = (dp[i + 1] + dp[i - 1]) % inf;
            }
        }
    }
    return dp[n];
}

class Solution
{
public:
    int numDecodings(string s)
    {
        return ans(s);
    }
};
