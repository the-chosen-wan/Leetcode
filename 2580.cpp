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

int ans(vector<int>& nums,int k){
    int n = nums.size();

    ll sum = accumulate(nums.begin(),nums.end(),0LL);

    if(sum<2*k)
        return 0;

    vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));

    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j] = dp[i-1][j];
            if(nums[i-1]>=j)
                dp[i][j] = (dp[i][j]+binpow(2,i-1))%inf;

            else if(nums[i-1]<j)
                dp[i][j] = (dp[i][j]+dp[i-1][j-nums[i-1]])%inf;
        }
    }

    vector<vector<ll>> ex(n+1,vector<ll>(k+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            ex[i][j] = ex[i-1][j];

            if(nums[i-1]==j)
                ex[i][j] = (ex[i][j]+1)%inf;
            
            else if(nums[i-1]<j)
                ex[i][j] = (ex[i][j]+ex[i-1][j-nums[i-1]])%inf;
        }
    }

    ll ans = dp[n][k];

    for(int i=1;i<k;i++)
        ans = (ans - ex[n][i])%inf;
    
    ans = (ans-1)%inf;

    if(ans<0)
        ans+=inf;
    
    return ans;
}

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        return ans(nums,k);
    }
};