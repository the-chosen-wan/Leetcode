#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
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
    t[v] = t[2 * v]+t[2 * v + 1];
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
    t[v] = t[2 * v]+t[2 * v + 1];
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
    return query(t, lazy, 2 * v, tl, tm, l, min(r, tm))+query(t, lazy, 2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

int ans(vector<int>& nums1,vector<int>& nums2,int diff){
    int n = nums1.size();
    vector<int> t(4*n+1,0),lazy(4*n+1,0);

    
}