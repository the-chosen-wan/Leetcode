#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
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
        return 0;
    if (l == tl && r == tr)
        return t[v];
    push(t, lazy, v);
    int tm = (tl + tr) / 2;
    return max(query(t, lazy, 2 * v, tl, tm, l, min(r, tm)), query(t, lazy, 2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int cons(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> results(n,-inf);
    deque<pii> window;

    results[0] = nums[0];
    window.pb(mp(0,nums[0]));

    for(int i=0;i<n;i++){
        results[i] = max(nums[i]+window.front().second,nums[i]);
        if(window.front().first == i-k)
            window.pop_front();
        pii temp = mp(i,results[i]);
        while(!window.empty()&&window.back().second<temp.second)
            window.pop_back();
        window.pb(temp);
    }

    int ret = -inf;
    for(int i=0;i<n;i++)
        ret = max(ret,results[i]);
    return ret;
}

class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        return cons(nums, k);
    }
};