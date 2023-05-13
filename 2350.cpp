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
    unordered_set<int> s;
    int c = k;
    int tot = 0;

    for (int i = 0; i < n; i++)
    {
        if (c == 0)
        {
            tot++;
            s.clear();
            c = k;
        }

        if (s.find(nums[i]) == s.end())
        {
            c--;
            s.insert(nums[i]);
        }
    }

    if (c == 0)
        tot++;

    return ++tot;
}

class Solution
{
public:
    int shortestSequence(vector<int> &rolls, int k)
    {
        return ans(rolls, k);
    }
};