#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(string s)
{
    unordered_map<char, int> m;
    int ret = -inf;
    int n = s.size();
    if (n == 0)
        return 0;
    int ans = 0;
    int low = 0;

    for (int i = 0; i < n; i++)
    {
        if (m.find(s[i]) == m.end())
        {
            ans++;
            m[s[i]] = 1;
        }

        else
        {
            m[s[i]]++;
            while (low < i && m[s[i]] != 1)
            {
                m[s[low]]--;
                if (m[s[low]] == 0)
                    m.erase(s[low]);
                low++;
            }
            ans = i - low + 1;
        }
        ret = max(ret, ans);
    }

    return ret;
}

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        return ans(s);
    }
};