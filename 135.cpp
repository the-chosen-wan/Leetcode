#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int mini(vector<int> &nums)
{
    int n = nums.size();
    vector<int> inc(n, 1);

    for (int i = 1; i < n; i++)
        if (nums[i - 1] < nums[i])
            inc[i] = inc[i - 1] + 1;

    vector<int> dec(n, 1);
    for (int i = n - 2; i >= 0; i--)
        if (nums[i] > nums[i + 1])
            dec[i] = dec[i + 1] + 1;

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += max(inc[i], dec[i]);

    return ans;
}

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        return mini(ratings);
    }
};
