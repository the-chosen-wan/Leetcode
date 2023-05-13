#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

string ans(vector<int>& nums){
    int n = nums.size();
    vector<int> suff(n);

    suff[n-1]=nums[n-1];
    for(int i=n-2;i>=0;i--)
        suff[i] = nums[i]+suff[i+1];
    
    vector<vector<int>> dp(n,vector<int>(2,0));
    dp[n-1][0]=nums[0];
    dp[n-1][1]=nums[0];

    if(n>=2){
        dp[n-2][0] = max(nums[n-2],nums[n-2]+nums[n-1]);
        dp[n-2][1]=dp[n-2][0];
    }

    if(n>=3){
        dp[n-3][0] = max({suff[n-3],suff[n-3]-suff[n-1],nums[n-3]+suff[n-2]-dp[n-2][0]});
        dp[n-3][1]=dp[n-3][0];
    }

    string ans = 'Bob';
    if(n<=3&&dp[n-1][0]>=)
}