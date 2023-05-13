#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
#define N (1e5)

int gcd(int x, int y)
{
    if (x < y)
        swap(x, y);
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

ll count(vector<int> &nums, int k)
{
    vector<int> facts;
    for (int i = 1; i <= N; i++)
        if (k % i == 0)
            facts.pb(i);

    int n = nums.size();
    int f = facts.size();

    map<int, int> mapa;
    for (int t : facts)
        mapa[t] = 0;

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int g = gcd(k, nums[i]);
        ans += mapa[k / g];
        for (int t : facts)
        {
            if (nums[i] % t == 0)
                mapa[t]++;
        }
    }
    return ans;
}

class Solution
{
public:
    long long countPairs(vector<int> &nums, int k)
    {
        return count(nums, k);
    }
};