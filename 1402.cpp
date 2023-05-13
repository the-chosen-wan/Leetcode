#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int sum(vector<int> &pref, int l, int r)
{
    if (l == 0)
        return pref[r];
    return pref[r] - pref[l - 1];
}

int maxa(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int positive = -1;
    vector<int> pref(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (positive == -1 && nums[i] >= 0)
        {
            positive = i;
            break;
        }
    }

    if (positive == -1)
        return 0;

    for (int i = 0, j = positive - 1; i <= j; i++, j--)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    pref[0] = nums[0];
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + nums[i];

    int suma = 0;
    int maxa = 0;

    for (int i = n - 1; i >= positive; i--)
        suma += sum(pref, i, n - 1);
    maxa = max(maxa, suma);
    for (int i = 0; i < positive; i++)
    {
        suma += (sum(pref, positive, n - 1) + sum(pref, 0, i));
        maxa = max(maxa, suma);
    }
    return maxa;
}

class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        return maxa(satisfaction);
    }
};