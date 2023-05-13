#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums, vector<int> &divide)
{
    sort(nums.begin(), nums.end());
    int n = divide.size();
    int g = divide[0];
    for (int i = 1; i < n; i++)
        g = __gcd(g, divide[i]);

    int n1 = nums.size();
    for (int i = 0; i < n1; i++)
        if (g % nums[i] == 0)
            return i;
    return -1;
}

class Solution
{
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        return ans(nums, numsDivide);
    }
};