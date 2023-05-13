#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

ll ans(vector<int> &nums, int k)
{
    int n = nums.size();
    ll summa=0;
    for(int v:nums)
        summa+=v;
    sort(nums.begin(), nums.end());

    vector<ll> all;
    int c = 0;

    for (int i = 0; i < n; i++)
    {

        ll val = nums[i];
        sort(all.begin(),all.end());
        vector<ll> temp;
        int len=all.size();
        for (int j=0;j<len;j++)
        {
            if (c == k)
                break;
            temp.pb(all[j] + val);
            c++;
        }
        for (ll v : temp)
            all.pb(v);
        if (c == k)
            break;
    }
    for(ll& v:all)
        v=summa-v;
    sort(all.begin(), all.end(),greater<ll>());
    for(ll a:all)
        cout<<a<<endl;
    return all[k - 1];
}

class Solution
{
public:
    long long kSum(vector<int> &nums, int k)
    {
        return ans(nums, k);
    }
};

int main(){
    vector<int> v={1,-2,3,4,-10,12};
    ans(v,16);
    return 0;
}