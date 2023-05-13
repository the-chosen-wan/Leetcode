#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll inf = (ll)1e14;
#define pb push_back
#define mp make_pair

bool check(ll time, int n, deque<ll> nums)
{

    int count = 0;
    while (!nums.empty())
    {
        if (nums.back() >= time)
        {
            nums.pop_back();
            count++;
        }
        else
        {
            if (nums.size() == 1)
            {
                if (count >= n)
                    return true;
                return false;
            }
            while (nums.size() > 1)
            {
                ll back = nums.back();
                ll front = nums.front();
                if (back + front < time)
                {
                    nums.pop_back();
                    nums.pb(back + front);
                    nums.pop_front();
                }
                else
                {
                    nums.pop_back();
                    nums.pop_front();
                    if (back + front - time != 0)
                        nums.push_front(back + front - time);
                    count++;
                    break;
                }
            }
        }
        if (count >= n)
            return true;
    }
    return false;
}

ll minnum(int n, vector<int> &batteries)
{
    deque<ll> dq;
    int len = batteries.size();
    for (int i = 0; i < len; i++)
        dq.pb(batteries[i]);

    sort(dq.begin(), dq.end());
    ll high = inf;
    ll low = 0;
    // return check(43,12,dq);

    while (high >= low)
    {
        ll mid = low + (high - low) / 2;
        if (mid == low)
        {
            if (check(high, n, dq))
                return high;
            return low;
        }
        bool chk = check(mid, n, dq);
        if (!chk)
            high = mid - 1;
        else
            low = mid;
    }
    return -1;
}

class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        return minnum(n, batteries);
    }
};