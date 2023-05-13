#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool can(vector<int> &nums)
{
    priority_queue<ll> pq;
    ll sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        pq.push(nums[i]);
        sum += nums[i];
    }
    if (n == 1 && nums[0] == 1)
        return true;
    else if (n == 1)
        return false;

    while (!pq.empty())
    {
        ll top = pq.top();
        if (top == 1)
            return true;
        pq.pop();
        ll sec = pq.top();
        ll n1 = (sum - sec) / (sum - top);
        if ((sum - sec) % (sum - top) != 0)
            n1++;
        // cout<<sum<<" "<<sec<<" "<<top<<endl;
        // cout<<n1<<endl;
        if (n1 <= 1)
            return false;
        if (n1 * top - (n1 - 1) * sum < 1)
            return false;
        pq.push(n1 * top - (n1 - 1) * sum);
        sum = (n1 - 1) * top - (n1 - 2) * sum;
    }
    return false;
}

class Solution
{
public:
    bool isPossible(vector<int> &target)
    {
        return can(target);
    }
};