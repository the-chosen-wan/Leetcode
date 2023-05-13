#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

ll ways(vector<string> &words, string target)
{
    int len = words.size();
    int wordlen = words[0].length();
    vector<vector<ll>> counter;
    counter.resize(wordlen,vector<ll>(26,0));

    for (int i = 0; i < wordlen; i++)
    {
        for (int j = 0; j < len; j++)
            counter[i][words[j][i]-'a']++;
    }

    int n = target.length();
    vector<vector<ll>> dp;
    dp.resize(wordlen, vector<ll>(n, 0));

    dp[0][0] = counter[0][target[0]-'a'];

    for (int i = 1; i < n; i++)
        dp[0][i] = 0;

    for (int i = 1; i < wordlen; i++)
        dp[i][0] = (dp[i - 1][0] + counter[i][target[0]-'a']) % inf;

    for (int i = 1; i < wordlen; i++)
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = (dp[i - 1][j] + (counter[i][target[j]-'a'] * dp[i - 1][j - 1]) % inf) % inf;
        }

    if (dp[wordlen - 1][n - 1] < 0)
        dp[wordlen - 1][n - 1] += inf;
    return dp[wordlen - 1][n - 1];
}

class Solution
{
public:
    int numWays(vector<string> &words, string target)
    {
        return ways(words, target);
    }
};