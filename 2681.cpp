#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair


ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % inf;
        a = (a * a) % inf;
        b >>= 1;
    }
    return res;
}

ll inverse(ll a){
    return binpow(a,inf-2);
}

int ans(vector<ll>& nums){
    sort(nums.begin(),nums.end());

    int n = nums.size();

    vector<ll> prefsum(n,0);

    prefsum[0] = nums[0];

    for(int i=1;i<n;i++){
        prefsum[i] = (prefsum[i-1] + ((nums[i]*inverse(binpow(2,i)))))%inf;
    }

    ll ans = 0;

    for(int i=1;i<n;i++){
        ans = (ans+((((nums[i]*nums[i])%inf)*binpow(2,i-1))%inf*prefsum[i-1]))%inf;
    }

    for(int i=0;i<n;i++)
        ans = (ans+(nums[i]*nums[i])%inf*nums[i])%inf;

    return ans;
}

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        vector<ll> temp(nums.begin(),nums.end());
        return ans(temp);
    }
};

int main(){
    cout<<"Hello world"<<endl;
}