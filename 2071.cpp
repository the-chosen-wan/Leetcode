#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool check(int num_tasks, vector<int> &tasks, vector<int> &worker, int pill, int strength)
{
    num_tasks--;
    int n = tasks.size();
    int w = worker.size();
    multiset<int> power;
    for (int i = 0; i < w; i++)
        power.insert(worker[i]);

    while (num_tasks >= 0)
    {
        if (!power.empty())
        {
            auto maxa = --power.end();
            if (*maxa >= tasks[num_tasks])
            {
                power.erase(maxa);
                num_tasks--;
                continue;
            }
        }

        if (pill == 0)
            return false;
        auto it = power.lower_bound(tasks[num_tasks] - strength);
        if (it == power.end())
            return false;
        power.erase(it);
        num_tasks--;
        pill--;
    }
    return true;
}

int ans(vector<int> &tasks, vector<int> &workers, int pill, int strength)
{
    sort(tasks.begin(), tasks.end());

    int n = tasks.size();
    int high = n;
    int low = 0;
    // cout<<check(3,tasks,workers,pill,strength);
    while (high >= low)
    {
        int mid = (high + low) / 2;
        if (mid == low)
        {
            if (check(high, tasks, workers, pill, strength))
                return high;
            return mid;
        }

        if (check(mid, tasks, workers, pill, strength))
            low = mid;
        else
            high = mid - 1;
    }
    return -1;
}

class Solution
{
public:
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        return ans(tasks, workers, pills, strength);
    }
};