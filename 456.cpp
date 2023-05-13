#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool ans(vector<int> &nums)
{
    int n = nums.size();

    stack<pii> sp;
    vector<int> closest(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (sp.empty())
            sp.push(mp(nums[i], i));
        else
        {
            pii top = sp.top();
            if (top.first > nums[i])
            {
                closest[i] = top.second;
                sp.push(mp(nums[i], i));
                continue;
            }

            while (top.first <= nums[i])
            {
                sp.pop();
                if (sp.empty())
                    break;
                top = sp.top();
            }
            if (!sp.empty())
                closest[i] = sp.top().second;
            sp.push(mp(nums[i], i));
        }
    }

    vector<int> farthest(n, -1);
    vector<int> prefmin(n, 0);
    prefmin[0] = nums[0];
    for (int i = 1; i < n; i++)
        prefmin[i] = min(prefmin[i - 1], nums[i]);

    for (int i = 0; i < n; i++)
    {
        int pos = upper_bound(prefmin.begin(), prefmin.end(), nums[i], greater<int>()) - prefmin.begin();
        if (pos <= i)
            farthest[i] = pos;
    }

    for (int i = 0; i < n; i++)
    {
        if (farthest[i] == -1 || closest[i] == -1)
            continue;
        if (farthest[i] < closest[i])
            return true;
    }
    return false;
}

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        return ans(nums);
    }
};