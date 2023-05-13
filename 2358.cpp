#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums)
{
    int ans = 1;
    int n = nums.size();
    while ((ans * (ans + 1)) / 2 <= n)
        ans++;

    return --ans;
}

class Solution
{
public:
    int maximumGroups(vector<int> &grades)
    {
        return ans(grades);
    }
};