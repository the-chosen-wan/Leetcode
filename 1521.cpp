#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define MAXN 1000000
#define bit 21
#define pb push_back
#define pf push_front
#define mp make_pair

int abs(int x)
{
    return x > 0 ? x : -x;
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
    t[v] = t[2 * v] & t[2 * v + 1];
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
    t[v] = t[2 * v] & t[2 * v + 1];
    return;
}
int query(vector<int> &t, vector<int> &lazy, int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return (1<<bit)-1;
    if (l == tl && r == tr)
        return t[v];
    push(t, lazy, v);
    int tm = (tl + tr) / 2;
    return query(t, lazy, 2 * v, tl, tm, l, min(r, tm)) & query(t, lazy, 2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

int query(int sz[][bit], int lg[MAXN],int L,int R ){
    int j = lg[R - L + 1];
    int minimum = min(sz[L][j], sz[R - (1 << j) + 1][j]);
}
int ret(vector<int> &nums, int target)
{
    int n = nums.size();
    int st[n+1][bit];
    for (int i = 0; i < n; i++)
        st[i][0] = nums[i];

    for (int j = 1; j < bit; j++)
        for (int i = 0; i + (1 << j) <=n; i++)
            st[i][j] = st[i][j - 1]&st[i + (1 << (j - 1))][j - 1];

    int lg[MAXN + 1];
    lg[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        lg[i] = lg[i / 2] + 1;

    // vector<int> t(4 * n + 1, 0);
    // vector<int> lazy(4 * n + 1, 0);
    int lastpos[bit];
    for (int i = 0; i < bit; i++)
        lastpos[i] = nums[0] & (1 << i) ? 0 : -1;
    
    int used = (1<<bit)-1;
    for(int i=0;i<n;i++)
        used&=nums[i];
    
    vector<int> used_indices;
    for(int i=0;i<bit;i++)
        if(!(used&(1<<i)))
            used_indices.pb(i);

    // build(t, nums, 1, 0, n - 1);
    int mini = abs(target - nums[0]);
    for (int i = 1; i < n; i++)
    {
        for (int j:used_indices)
        {
            if (lastpos[j] != -1)
                mini = min(mini, abs(target - query(st,lg,lastpos[j],i)));
            if (lastpos[j] == -1 && (nums[i] & (1 << j)))
                lastpos[j] = i;
            if (!(nums[i] & (1 << j)))
                lastpos[j] = -1;
        }
        mini = min(mini, abs(target - nums[i]));
    }
    return mini;
}

// int main(){
//     vector<int> v = {23, 43, 16, 25, 31, 45, 14, 20, 21, 38};
//     int target = 8;
//     cout<<ret(v,target)<<endl;
// }

class Solution
{
public:
    int closestToTarget(vector<int> &arr, int target)
    {
        return ret(arr, target);
    }
};

