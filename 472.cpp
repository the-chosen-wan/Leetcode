#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool comp(string &s1, string &s2)
{
    return s1.length() <= s2.length();
}

vector<string> ans(vector<string> &words)
{
    unordered_set<string> hash;
    int n = words.size();

    sort(words.begin(), words.end(), comp);
    vector<string> ans;

    for (int i = 0; i < n; i++)
    {
        int l = words[i].length();
        if (!hash.empty())
        {
            vector<bool> dp(l, false);
            for (int j = 0; j < l; j++)
            {
                if (hash.find(words[i].substr(j)) != hash.end())
                    dp[j] = true;
            }
            for (int j = l - 2; j >= 0; j--)
            {
                if (dp[j])
                    continue;
                for (int k = j + 1; k < l; k++)
                {
                    if ((hash.find(words[i].substr(j, k - j)) != hash.end()) && dp[k])
                    {
                        dp[j] = true;
                        break;
                    }
                }
            }
            if (dp[0])
                ans.pb(words[i]);
        }
        hash.insert(words[i]);
    }
    return ans;
}
class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        return ans(words);
    }
};