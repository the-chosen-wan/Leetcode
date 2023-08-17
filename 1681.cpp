#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using namespace std;
const int inf = 1e8;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums, int k){
    int n = nums.size();
    vector<vector<int>> dp(k+1,vector<int>(1<<n,inf));

    int localmax = -inf;
    int localmin = inf;

    auto dfs = [&](int i,int mask,auto&& dfs)->int{
        if(i==0&&mask!=0){
            return 2*inf;
        }

        if(i==0&&mask==0){
            dp[i][mask]=0;
            return 0;
        }

        if(dp[i][mask]!=inf)
            return dp[i][mask];

        int state1 = localmax;
        int state2 = localmin;

        if(localmax!=-inf&&localmin!=inf){
            int val = localmax-localmin;
            localmax = -inf;
            localmin = inf;
            dp[i][mask] = min(dp[i][mask],val+dfs(i-1,mask,dfs));
        }

        localmax = state1;
        localmin = state2;

        for(int j=0;j<n;j++){
            if(mask&(1<<j)){

                localmax = max(localmax,nums[j]);
                localmin = min(localmin,nums[j]);

                dp[i][mask] = min(dp[i][mask],dfs(i,mask^(1<<j),dfs));

                localmax = state1;
                localmin = state2;
            }
        }
        return dp[i][mask];
    };

    return dfs(k,(1<<n)-1,dfs);
}

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        return ans(nums,k);
    }
};