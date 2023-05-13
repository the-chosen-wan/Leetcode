#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll inf = 1e9;
#define pb push_back
#define pf push_front
#define mp make_pair

vector<ll> merge(vector<ll> &v1, int &c)
{
    int s = v1.size();
    if (s == 1)
        return v1;
    vector<ll> first;
    vector<ll> second;

    for (int i = 0; i < s; i++)
    {
        if (i < s / 2)
            first.pb(v1[i]);
        else
            second.pb(v1[i]);
    }

    first = merge(first, c);
    second = merge(second, c);

    vector<ll> third = second;
    for (ll &v : second)
        v *= 2;

    int s1 = first.size();
    int s2 = second.size();

    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    while (c1 <= s1 && c2 <= s2)
    {
        if (c1 == s1 && c2 == s2)
            break;
        if (c1 == s1)
        {
            v1[c3] = second[c2];
            c2++;
            c3++;
        }
        else if (c2 == s2)
        {
            v1[c3] = first[c1];
            c += s2;
            c1++;
            c3++;
        }
        else if (first[c1] <= second[c2])
        {
            v1[c3] = first[c1];
            c += c2;
            c1++;
            c3++;
        }
        else if (second[c2] < first[c1])
        {
            v1[c3] = second[c2];
            c2++;
            c3++;
        }
    }

    c1 = 0;
    c2 = 0;
    c3 = 0;
    while (c1 <= s1 && c2 <= s2)
    {
        if (c1 == s1 && c2 == s2)
            break;
        if (c1 == s1)
        {
            v1[c3] = third[c2];
            c2++;
            c3++;
        }
        else if (c2 == s2)
        {
            v1[c3] = first[c1];
            c1++;
            c3++;
        }
        else if (first[c1] <= third[c2])
        {
            v1[c3] = first[c1];
            c1++;
            c3++;
        }
        else if (third[c2] < first[c1])
        {
            v1[c3] = third[c2];
            c2++;
            c3++;
        }
    }
    return v1;
}

int ans(vector<int> &nums1)
{
    int n = nums1.size();
    vector<ll> nums(nums1.begin(), nums1.end());
    int c = 0;
    nums = merge(nums, c);
    return c;
}

class Solution
{
public:
    ll reversePairs(vector<int> &nums)
    {
        return ans(nums);
    }
};