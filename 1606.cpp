#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

vector<int> busy(int k, vector<int> &arrival, vector<int> &load)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    set<int> s;

    for (int i = 0; i < k; i++)
        s.insert(i);

    vector<int> counter(k, 0);

    for (int i = 0; i < arrival.size(); i++)
    {
        if (!pq.empty())
        {
            pii top = pq.top();
            while (top.first <= arrival[i])
            {
                pq.pop();
                s.insert(top.second);
                if (pq.empty())
                    break;
                top = pq.top();
            }
        }

        if (!s.empty())
        {
            int ind = i % k;
            auto it = s.lower_bound(ind);
            int pos = it == s.end() ? *s.begin() : *it;
            s.erase(pos);
            pq.push(mp(arrival[i] + load[i], pos));
            counter[pos]++;
        }
    }

    int maxa = -inf;
    for (int c : counter)
        maxa = max(c, maxa);

    vector<int> ans;
    for (int i = 0; i < counter.size(); i++)
    {
        if (counter[i] == maxa)
            ans.pb(i);
    }

    return ans;
}

class Solution
{
public:
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load)
    {
        return busy(k, arrival, load);
    }
};