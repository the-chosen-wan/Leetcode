#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e7;
#define pb push_back
#define pf push_front
#define mp make_pair
const int N = (1e5)+1;

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
    lazy[2 * v + 1]+= lazy[v];
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

int ans(vector<int>& nums,int k){
    int n = nums.size();
    vector<int> t(4*N+1,0);
    vector<int> lazy(4*N+1,0);

    int maxa = -inf;

    for(int i=0;i<n;i++){
        int val = query(t,lazy,1,0,N-1,max(0,nums[i]-k),nums[i]-1);
        maxa = max(maxa,val+1);
        int temp = query(t,lazy,1,0,N-1,nums[i],nums[i]);
        update(t,lazy,1,0,N-1,nums[i],nums[i],val+1-temp);
    }
    return maxa;
}

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums, int k)
    {
        return ans(nums,k);
    }
};

int main(){
    vector<int> nums={1,2,3,4,5,6};
    cout<<ans(nums,2)<<endl;
}