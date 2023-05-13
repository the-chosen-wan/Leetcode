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
    int x = 0;
    for (int i = 0; i < nums.size(); i++)
        x ^= nums[i];

    if (x == 0)
        return true;
    return (nums.size() & 1) != 1;
}

class Solution
{
public:
    bool xorGame(vector<int> &nums)
    {
        return ans(nums);
    }
};