#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

int ans(int h, int w, vector<int> &hori, vector<int> &verti)
{
    sort(hori.begin(), hori.end());
    sort(verti.begin(), verti.end());
    int mh = -inf;
    mh = max({mh, hori[0] - 0, h - hori[hori.size() - 1]});

    int mw = -inf;
    mw = max({mw, verti[0] - 0, w - verti[verti.size() - 1]});

    int hlen = hori.size();
    int vlen = verti.size();

    for (int i = 0; i < hlen - 1; i++)
        mh = max(mh, hori[i + 1] - hori[i]);

    for (int i = 0; i < vlen - 1; i++)
        mw = max(mw, verti[i + 1] - verti[i]);

    ll ret = ((ll)mh * (ll)mw) % inf;
    return ret;
}

class Solution
{
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        return ans(h, w, horizontalCuts, verticalCuts);
    }
};