#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll inf = (1e15) + 7;
#define pb push_back
#define mp make_pair

ll ans(vector<int> &pack, vector<vector<int>> &box)
{
    int n = pack.size();
    sort(pack.begin(), pack.end());
    vector<ll> prefsum(n, 0);
    prefsum[0] = pack[0];
    for (int i = 1; i < n; i++)
        prefsum[i] = prefsum[i - 1] + pack[i];

    auto query = [&](int p) -> ll
    {
        if (p > 0)
            return prefsum[p - 1];
        return 0;
    };

    int b = box.size();
    bool flag = false;
    ll mini = inf;

    for (int i = 0; i < b; i++)
    {
        ll sum = 0;
        ll low = 0;
        ll high = 0;
        sort(box[i].begin(), box[i].end());
        for (int &val : box[i])
        {
            int pos = upper_bound(pack.begin(), pack.end(), val) - pack.begin();
            sum += (pos - high) * val - query(pos) + query(high);
            low = high;
            high = pos;
        }
        if (high == n)
        {
            flag = true;
            mini = min<ll>(mini, sum);
        }
    }
    if (!flag)
        return -1;
    return mini % (1000000007);
}

class Solution
{
public:
    int minWastedSpace(vector<int> &packages, vector<vector<int>> &boxes)
    {
        return ans(packages, boxes);
    }
};