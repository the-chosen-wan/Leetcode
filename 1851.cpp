#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

vector<int> count(vector<vector<int>> &interval, vector<int> &q)
{
    vector<pii> query;
    for (int i = 0; i < q.size(); i++)
        query.pb(mp(q[i], i));

    vector<pii> start;
    vector<pii> end;

    for (int i = 0; i < interval.size(); i++)
    {
        int val = interval[i][1] - interval[i][0] + 1;
        start.pb(mp(interval[i][0], val));
        end.pb(mp(interval[i][1], val));
    }

    multiset<int> s;

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    sort(query.begin(), query.end());
    vector<int> ans(query.size());
    int n = start.size();
    int c_start = 0;
    int c_end = 0;

    for (int i = 0; i < query.size(); i++)
    {
        while (c_start < n && start[c_start].first <= query[i].first)
        {
            s.insert(start[c_start].second);
            c_start++;
        }
        while (c_end < n && end[c_end].first < query[i].first)
        {
            s.erase(s.find(end[c_end].second));
            c_end++;
        }
        if (s.empty())
            ans[query[i].second] = -1;
        else
            ans[query[i].second] = *s.begin();
    }
    return ans;
}

class Solution
{
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
    {
        return count(intervals, queries);
    }
};