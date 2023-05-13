#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int mini(int target, int start, vector<vector<int>> &station)
{
    priority_queue<int> pq;
    int len = station.size();
    int minnum = 0;

    if (len == 0)
    {
        if (start >= target)
            return 0;
        return -1;
    }

    for (int i = 0; i < len; i++)
    {
        if (start >= target)
            return minnum;

        int pos = station[i][0];
        int fuel = station[i][1];

        if (start < pos)
        {
            while (!pq.empty())
            {
                start += pq.top();
                pq.pop();
                minnum++;
                if (start >= pos)
                    break;
            }
        }

        if (start < pos)
            return -1;
        pq.push(fuel);
    }

    if (start < target)
    {
        while (!pq.empty())
        {
            start += pq.top();
            pq.pop();
            minnum++;
            if (start >= target)
                return minnum;
        }
        return -1;
    }

    return minnum;
}

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        return mini(target, startFuel, stations);
    }
};