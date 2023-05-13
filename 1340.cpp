#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e7;
#define pb push_back
#define pf push_front
#define mp make_pair

void build(vector<int> &t, vector<int> &a, int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
        return;
    }
    int mid = tl + (tr - tl) / 2;
    build(t, a, 2 * v, tl, mid);
    build(t, a, 2 * v + 1, mid + 1, tr);
    t[v] = max(t[2 * v], t[2 * v + 1]);
    return;
}
void push(vector<int> &t, vector<int> &lazy, int v)
{
    t[2 * v] += lazy[v];
    t[2 * v + 1] += lazy[v];
    lazy[2 * v] += lazy[v];
    lazy[2 * v + 1] += lazy[v];
    lazy[v] = 0;
    return;
}
void update(vector<int> &t, vector<int> &lazy, int v, int tl, int tr, int l, int r, int add)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[v] += add;
        lazy[v] += add;
        return;
    }
    push(t, lazy, v);
    int tm = (tl + tr) / 2;
    update(t, lazy, 2 * v, tl, tm, l, min(r, tm), add);
    update(t, lazy, 2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);
    t[v] = max(t[2 * v], t[2 * v + 1]);
    return;
}
int query(vector<int> &t, vector<int> &lazy, int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return -inf;
    if (l == tl && r == tr)
        return t[v];
    push(t, lazy, v);
    int tm = (tl + tr) / 2;
    return max(query(t, lazy, 2 * v, tl, tm, l, min(r, tm)), query(t, lazy, 2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int ans(vector<int> &nums, int d)
{
    int n = nums.size();
    vector<int> t(4 * n + 1, -inf);
    vector<int> lazy(4 * n + 1, 0);

    vector<int> prevpos(n, 0);
    stack<pii> sp;

    for (int i = 0; i < n; i++)
    {
        if (sp.empty())
            sp.push(mp(nums[i], i));
        else
        {
            pii top = sp.top();
            if (top.first >= nums[i])
            {
                sp.push(mp(nums[i], i));
                prevpos[i] = i;
                continue;
            }

            while (top.first < nums[i])
            {
                sp.pop();
                if (sp.empty())
                    break;
                top = sp.top();
            }

            if (!sp.empty())
                prevpos[i] = max(sp.top().second + 1, i - d);
            else
                prevpos[i] = max(0, i - d);
            sp.push(mp(nums[i], i));
        }
    }

    vector<int> nextpos(n, n - 1);
    while (!sp.empty())
        sp.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        if (sp.empty())
            sp.push(mp(nums[i], i));
        else
        {
            pii top = sp.top();
            if (top.first >= nums[i])
            {
                sp.push(mp(nums[i], i));
                nextpos[i] = i;
                continue;
            }

            while (top.first < nums[i])
            {
                sp.pop();
                if (sp.empty())
                    break;
                top = sp.top();
            }

            if (!sp.empty())
                nextpos[i] = min(sp.top().second - 1, i + d);
            else
                nextpos[i] = min(n - 1, i + d);
            sp.push(mp(nums[i], i));
        }
    }

    vector<pii> pairs;
    for (int i = 0; i < n; i++)
        pairs.pb(mp(nums[i], i));
    sort(pairs.begin(), pairs.end());

    int maxa = -inf;
    for (int i = 0; i < n; i++)
    {
        int val = query(t, lazy, 1, 0, n - 1, prevpos[pairs[i].second], nextpos[pairs[i].second]);
        if (val == -inf)
            val = 0;
        val++;
        update(t, lazy, 1, 0, n - 1, pairs[i].second, pairs[i].second, val + inf);
        maxa = max(maxa, val);
    }
    return maxa;
}

class Solution
{
public:
    int maxJumps(vector<int> &arr, int d)
    {
        return ans(arr, d);
    }
};
