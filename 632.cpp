#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

vector<int> ans(vector<vector<int>> &nums)
{
    vector<int> ans(2);
    int n = nums.size();
    vector<int> prevpos(n, -inf);
    vector<int> currind(n, 0);
    multiset<int> minpos;
    int maxlen = inf;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(mp(nums[i][0], i));
        minpos.insert(-inf);
    }

    while (!pq.empty())
    {
        pii top = pq.top();
        pq.pop();
        minpos.erase(minpos.find(prevpos[top.second]));
        int val = minpos.empty() ? top.first : *minpos.begin();

        if (val != -inf)
        {
            if (maxlen > (top.first - val + 1))
            {
                maxlen = top.first - val + 1;
                ans[0] = val;
                ans[1] = top.first;
            }
        }
        prevpos[top.second] = top.first;
        minpos.insert(top.first);

        currind[top.second]++;
        if (currind[top.second] != nums[top.second].size())
            pq.push(mp(nums[top.second][currind[top.second]], top.second));
    }
    return ans;
}

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        return ans(nums);
    }
};