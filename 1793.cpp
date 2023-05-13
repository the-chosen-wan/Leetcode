#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> declen(n, 1);
    stack<pii> s;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            s.push(mp(nums[i], i));
        }
        else
        {
            pii top = s.top();
            if (top.first < nums[i])
            {
                s.push(mp(nums[i], i));
                continue;
            }

            while (top.first >= nums[i])
            {
                s.pop();
                if (s.empty())
                    break;
                top = s.top();
            }

            if (s.empty())
                declen[i] = i + 1;
            else
                declen[i] = i - s.top().second;
            s.push(mp(nums[i], i));
        }
    }

    s = stack<pii>();
    vector<int> rdeclen(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            s.push(mp(nums[i], i));
        }
        else
        {
            pii top = s.top();
            if (top.first < nums[i])
            {
                s.push(mp(nums[i], i));
                continue;
            }

            while (top.first >= nums[i])
            {
                s.pop();
                if (s.empty())
                    break;
                top = s.top();
            }
            if (s.empty())
                rdeclen[i] = n - i;
            else
                rdeclen[i] = s.top().second - i;
            s.push(mp(nums[i], i));
        }
    }

    int ans = -inf;
    // cout<<declen[1]<<" "<<rdeclen[1]<<endl;
    for (int i = 0; i < n; i++)
    {
        if (i - declen[i] + 1 > k || i + rdeclen[i] - 1 < k)
            continue;
        ans = max(ans, (declen[i] + rdeclen[i] - 1) * nums[i]);
    }
    return ans;
}

class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        return ans(nums, k);
    }
};