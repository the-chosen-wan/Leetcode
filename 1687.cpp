#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using namespace std;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

void initialize(int n, vector<int> &t, vector<int> &lazy)
{
    t.resize(4 * n + 1, 0);
    lazy.resize(4 * n + 1, 0);
    return;
}

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
    t[v] = min(t[2 * v], t[2 * v + 1]);
    return;
}

void push(vector<int> &t, vector<int> &lazy, int v)
{
    t[2 * v + 1] += lazy[v];
    t[2 * v] += lazy[v];
    lazy[2 * v + 1] += lazy[v];
    lazy[2 * v] += lazy[v];
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
    int mid = tl + (tr - tl) / 2;
    update(t, lazy, 2 * v, tl, mid, l, min(r, mid), add);
    update(t, lazy, 2 * v + 1, mid + 1, tr, max(l, mid + 1), r, add);
    t[v] = min(t[2 * v + 1], t[2 * v]);
    return;
}

int query(vector<int> &t, vector<int> &lazy, int v, int tl, int tr, int l, int r)
{
    if (l > r)
    {
        return inf;
    }

    if (tl == l && tr == r)
        return t[v];

    push(t, lazy, v);
    int mid = tl + (tr - tl) / 2;
    int val1 = query(t, lazy, 2 * v, tl, mid, l, min(r, mid));
    int val2 = query(t, lazy, 2 * v + 1, mid + 1, tr, max(l, mid + 1), r);
    return min(val1, val2);
}

int ans(vector<vector<int>> &boxes, int ports, int count, int weight)
{
    int n = boxes.size();
    vector<int> t, lazy;
    initialize(n + 1, t, lazy);
    vector<int> prevpos(n, 0);
    int low = 0;
    int currcount = 0;
    int currweight = 0;

    for (int i = 0; i < n; i++)
    {
        currcount++;
        currweight += boxes[i][1];
        while (currcount > count || currweight > weight)
        {
            currcount--;
            currweight -= boxes[low][1];
            low++;
        }
        prevpos[i] = low;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int ind = prevpos[i - 1];
        if (i > 1 && boxes[i - 1][0] != boxes[i - 2][0])
            update(t, lazy, 1, 0, n, 0, i - 2, 1);
        // else
        //     update(t,lazy,1,0,n,i-1,i-1,1);
        // }
        int ans = query(t, lazy, 1, 0, n, ind, i - 1);
        ans += 2;
        dp[i] = ans;
        update(t, lazy, 1, 0, n, i, i, ans);
    }
    return dp[n];
}

int main(){
    vector<vector<int>> v = {{1,0},{2,0},{2,0}};
    int c=2;int b=1;int w=3;
    cout<<ans(v,c,b,w);
}

class Solution
{
public:
    int boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes, int maxWeight)
    {
        return ans(boxes, portsCount, maxBoxes, maxWeight);
    }
};
