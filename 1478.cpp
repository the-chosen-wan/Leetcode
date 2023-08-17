#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int ans(vector<int>& nums,int k){
    sort(nums.begin(),nums.end());
    int n = nums.size();
    vector<int> prefsum(n,0);
    prefsum[0] = nums[0];

    for(int i=1;i<n;i++)
        prefsum[i] = prefsum[i-1]+nums[i];
    
    auto getrange = [&](int l,int r)->int{
        if(l==0)
            return prefsum[r];
        return prefsum[r]-prefsum[l-1];
    };

    auto getmedian = [&](int low,int high)->int{
        int mid = low + (high-low)/2;

        int nummid = (2*mid - low - high)*nums[mid];
        int sum = getrange(mid,high) - getrange(low,mid);
        return sum+nummid;
    };

    vector<vector<int>> dp(n,vector<int>(k+1,inf));

    for(int i=0;i<k;i++){
        dp[i][i+1] = 0;
    }

    for(int i=0;i<n;i++)
        dp[i][0]=inf;
    

    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            int maxa = inf;

            for(int l=j;l>=0;l--){
                maxa = min(maxa,getmedian(l,j)+ (l==0?0:dp[l-1][i-1]));
            }

            dp[j][i] = min(dp[j][i],maxa);
        }
    }
    return dp[n-1][k];
}

class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        return ans(houses,k);
    }
};