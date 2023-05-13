#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;
#define inf (ll)((1e9) + 7)
#define pb push_back
#define mp make_pair

long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % inf;
        a = (a * a) % inf;
        b >>= 1;
    }
    return res;
}

ll inverse(ll a)
{
    return binpow(a, inf - 2);
}

ll ans(vector<int> &speed, vector<int> &efficiency, int k)
{
    vector<pii> eff;
    int n = speed.size();
    for (int i = 0; i < n; i++)
        eff.pb(mp(efficiency[i], i));

    sort(eff.begin(), eff.end(), greater<pii>());
    ll maxa = 0;
    ll sum = 0;
    ll k_th = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        maxa = max(maxa, (k_th + speed[eff[i].second]) * eff[i].first);
        if (pq.size() == k - 1)
        {
            if (!pq.empty())
            {
                if (speed[eff[i].second] > pq.top())
                {
                    k_th += speed[eff[i].second];
                    k_th -= pq.top();
                    pq.pop();
                    pq.push(speed[eff[i].second]);
                }
            }
        }
        else
        {
            pq.push(speed[eff[i].second]);
            k_th += speed[eff[i].second];
        }
    }
    return maxa % inf;
}

class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        return ans(speed, efficiency, k);
    }
};