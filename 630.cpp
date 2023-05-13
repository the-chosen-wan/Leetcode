#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool comp(pii &a, pii &b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int ans(vector<vector<int>> &time)
{
    int n = time.size();
    vector<pii> jobs;

    for (int i = 0; i < n; i++)
        jobs.pb(mp(time[i][1], time[i][0]));

    sort(jobs.begin(), jobs.end());

    priority_queue<int> pq;

    int sum = 0;
    int maxa = 0;
    int count = 0;

    for (int i = 0; i < jobs.size(); i++)
    {
        if (pq.empty())
        {
            if (jobs[i].second <= jobs[i].first)
            {
                sum += jobs[i].second;
                maxa = jobs[i].first;
                pq.push(jobs[i].second);
                count++;
            }
        }
        else
        {
            int temp = maxa;
            maxa = jobs[i].first;
            sum += jobs[i].second;
            if (sum <= maxa)
            {
                count++;
                pq.push(jobs[i].second);
                continue;
            }
            maxa = temp;
            sum -= jobs[i].second;
            int top = pq.top();
            if (jobs[i].second > top)
                continue;
            maxa = jobs[i].first;
            sum += (jobs[i].second - top);
            pq.pop();
            pq.push(jobs[i].second);
        }
    }
    return count;
}

class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        return ans(courses);
    }
};