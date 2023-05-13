#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int mini(int n, vector<int> &taps)
{
    vector<pii> ranges;

    for (int i = 0; i < taps.size(); i++)
        ranges.pb(mp(max(0, i - taps[i]), min(n, i + taps[i])));

    int c = 0;
    sort(ranges.begin(), ranges.end());

    priority_queue<int> pq;

    int higher = 1;

    for (int i = 0; i < ranges.size(); i++)
    {
        if (ranges[i].first <= higher)
            pq.push(ranges[i].second - higher + 1);
        else
        {
            int val = pq.top();
            if (val < 0)
                return -1;
            higher += val;
            c++;
            pq = priority_queue<int>();
            if (ranges[i].first > higher)
                return -1;
            pq.push(ranges[i].second - higher + 1);
        }
    }
    return c;
}

class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        return mini(n, ranges);
    }
};
