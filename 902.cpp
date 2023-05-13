#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

int ans(vector<string> &digits, int n)
{
    vector<int> ndigits;

    unordered_set<int> valid;
    for (int i = 0; i < digits.size(); i++)
        valid.insert(digits[i][0] - '0');
    int cnt = 0;

    while (n != 0)
    {
        ndigits.pb(n % 10);
        n /= 10;
        cnt++;
    }

    int total = 0;
    vector<vector<int>> dp(cnt, vector<int>(2, -1));

    auto dfs = [&](int pos, int flag, auto &&dfs) -> int
    {
        if (pos == -1)
            return 1;
        if (dp[pos][flag] != -1)
            return dp[pos][flag];

        int ret = 0;

        int limit = flag == 1 ? 9 : ndigits[pos];

        for (int i = 1; i <= limit; i++)
        {
            if (valid.find(i) == valid.end())
                continue;
            int new_flag = flag == 1 ? flag : (i < ndigits[pos]);
            ret += dfs(pos - 1, new_flag, dfs);
        }
        dp[pos][flag] = ret;
        return dp[pos][flag];
    };
    int tot = 0;
    tot += dfs(cnt - 1, 0, dfs);
    for (int i = 0; i <= cnt - 2; i++)
    {
        dp.assign(cnt, vector<int>(2, -1));
        tot += dfs(i, 1, dfs);
    }
    return tot;
}

class Solution
{
public:
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        return ans(digits, n);
    }
};
