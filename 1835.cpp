#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums1, vector<int> &nums2)
{
    int ret = 0;
    int n1 = nums1.size();
    int n2 = nums2.size();
    for (int i = 31; i >= 0; i--)
    {
        ll c1 = 0;
        ll c2 = 0;
        for (int j = 0; j < n1; j++)
            if (nums1[j] & (1 << i))
                c1++;
        for (int j = 0; j < n2; j++)
            if (nums2[j] & (1 << i))
                c2++;
        ll tot = c1 * c2;
        if (tot & 1)
            ret += (1 << i);
    }
    return ret;
}

class Solution
{
public:
    int getXORSum(vector<int> &arr1, vector<int> &arr2)
    {
        return ans(arr1, arr2);
    }
};