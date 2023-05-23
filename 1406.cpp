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

    vector<int> dp(n,-inf);
    vector<int> prefsum(n,0);
    prefsum[0] = nums[0];

    for(int i=1;i<n;i++)
        prefsum[i] = prefsum[i-1]+nums[i];
    
    auto range = [&](int l,int r)->int{
        if(l==0)
            return prefsum[r];
        return prefsum[r]-prefsum[l-1];
    };

    auto dfs =[&](int pos,auto&& dfs)->int{
        if(dp[pos]!=-inf)
            return dp[pos];
        
        if(pos==n-1){
            dp[pos]=nums[n-1];
            return dp[pos];
        }

        if(pos+1<n)
            dp[pos] = max(dp[pos],nums[pos]+range(pos+1,n-1)-dfs(pos+1,dfs));
        
        if(pos+2<n)
            dp[pos] = max(dp[pos],nums[pos]+nums[pos+1]+range(pos+2,n-1)-dfs(pos+2,dfs));
        
        if(pos+3<n)
            dp[pos] = max(dp[pos],nums[pos]+nums[pos+1]+nums[pos+2]+range(pos+3,n-1)-dfs(pos+3,dfs));

        if(pos+1==n-1)
            dp[pos] = max(dp[pos],nums[pos]+nums[pos+1]);
        if(pos+2==n-1)
            dp[pos] = max(dp[pos],nums[pos]+nums[pos+1]+nums[pos+2]);

        return dp[pos];
    };

    dfs(0,dfs);
    if(dp[0]>range(0,n-1)-dp[0])
        return "Alice";
    else if(dp[0]<range(0,n-1)-dp[0])
        return "Bob";
    return "Tie";
}

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        return ans(stoneValue);
    }
};