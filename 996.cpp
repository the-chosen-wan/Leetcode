
#pragma GCC optimize("Ofast")
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define pb push_back
#define mp make_pair


int ans(vector<int>& nums,int slots){
    int inf = (1e6)+7;
    int n = nums.size();

    vector<vector<int>> dp(2*slots+1,vector<int>(1<<n,-1));

    auto dfs = [&](int slotna,int mask,auto&& dfs)->int{
        if(slotna==0){
            if(mask!=0)
                return -inf;
            else{
                dp[slotna][mask]=0;
                return 0;
            }
        }


        if(dp[slotna][mask]!=-1)
            return dp[slotna][mask];
        
        dp[slotna][mask] = max(dp[slotna][mask],dfs(slotna-1,mask,dfs));

        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                dp[slotna][mask] = max(dp[slotna][mask],((((slotna+1)>>1))&nums[i]) + dfs(slotna-1,mask^(1<<i),dfs));
            }
        }
        return dp[slotna][mask];
    };

    return dfs(2*slots,(1<<n)-1,dfs);
}

class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        return ans(nums,numSlots);
    }
};