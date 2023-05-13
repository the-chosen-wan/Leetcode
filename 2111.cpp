#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

class Solution
{
    int n, m;
    vector<pair<int, int>> v;
    int dp[5001][5001];      // sum index
    int pointer[5001][5001]; // no init needed
    string make_string(int sum, int index)
    {
        string ans;
        while (sum >= 0 and index < n)
        {
            ans += (pointer[sum][index] + '0');
            if (!pointer[sum][index])
            {
                sum -= v[index].first;
            }
            else
            {
                sum -= v[index].second;
            }
            index++;
        }
        return ans;
    }
    vector<string> give_ans(vector<vector<int>> v1, int n, int m)
    {
        vector<pair<int, int>> v;
        vector<string> s;
        int len = v1.size();
        for (int i = 0; i < len; i++)
            v.push_back(make_pair(v1[i][0], v1[i][1]));
        memset(dp, -1, sizeof(dp));
        this->n = n;
        this->m = m;
        this->v = v;
        int ans = func(m, 0);
        if (!ans)
        {
            s.push_back("NO");
        }
        else
        {
            s.push_back("YES");
            s.pb(make_string(m, 0));
        }
        return s;
    }
    int func(int sum, int index)
    {
        if (sum < 0)
        {
            return 0;
        }
        else if (index >= n)
        {
            return !sum;
        }
        else if (dp[sum][index] != -1)
        {
            return dp[sum][index];
        }
        else
        {
            int ans = 0;
            int a = func(sum - v[index].first, index + 1);
            int b = func(sum - v[index].second, index + 1);
            if (a)
            {
                pointer[sum][index] = 0;
            }
            else if (b)
            {
                pointer[sum][index] = 1;
            }
            return dp[sum][index] = (a | b);
        }
    }
};