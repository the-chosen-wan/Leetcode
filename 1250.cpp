#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool ret(vector<int> &nums)
{
    int a = nums[0];
    int n = nums.size();

    for (int i = 1; i < n; i++)
        a = __gcd(a, nums[i]);
    return a == 1;
}

class Solution
{
public:
    bool isGoodArray(vector<int> &nums)
    {
        return ret(nums);
    }
};