#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

int ans(vector<int>& nums,int k){
    int n = nums.size();

    ll sum = accumulate(nums.begin(),nums.end(),0);

    if(sum<k)
        return 0;

    vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));

    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j] = dp[i-1][j];
            if(nums[i-1]>=j)
                dp[i][j] = (dp[i][j]+dp[i-1][j]+1)%inf;

            if(nums[i-1]<j)
                dp[i][j] = (dp[i][j]+dp[i-1][j-nums[i-1]])%inf;
        }
    }

    vector<vector<ll>> exact(n+1,vector<ll>(k+1,0));

    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            exact[i][j] = exact[i-1][j];

            if(nums[i-1]==j)
                exact[i][j] = (exact[i][j]+1)%inf;
            
            else if(nums[i-1]<j)
                exact[i][j] = (exact[i][j]+exact[i-1][j-nums[i-1]])%inf;
        }
    }

    ll ans = dp[n][k];

    for(int i=1;i<k;i++)
        ans = (ans - exact[n][i])%inf;
    
    ans = (ans-1)%inf;

    if(ans<0)
        ans+=inf;
    
    return (2*ans)%inf;
}

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        return ans(nums,k);
    }
};