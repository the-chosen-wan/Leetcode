#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include<chrono>
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

int ans(vector<int>& cost,vector<int>& time){
    int n = cost.size();

    vector<pii> nums;

    for(int i=0;i<n;i++){
        nums.pb(mp(time[i],cost[i]));
    }

    sort(nums.begin(),nums.end(),greater<pii>());

    vector<int> timesum(n,0);
    vector<int> costsum(n,0);
    timesum[0] = nums[0].first;
    costsum[0] = nums[0].second;

    for(int i=1;i<n;i++){
        timesum[i] = timesum[i-1] + nums[i].first;
        costsum[i] = costsum[i-1] + nums[i].second;
    }

    vector<vector<int>> dp(n+1,vector<int>(n,inf+1));

    auto dfs = [&](int i,int j,auto&& dfs) -> int{

        if(i==0 && j>=0) {
            return 0;
        }

        if(i-1>j || j<0){
            return inf;
        }

        if(dp[i][j]!=(inf+1))
            return dp[i][j];

        if(i-1==j) {
            dp[i][j] = costsum[j];
            return dp[i][j];
        }

        dp[i][j] = min(dp[i][j],dfs(i,j-1,dfs));

        if(i-1<=j-1) {
            if(timesum[i-1] >= n-i+1) {
                dp[i][j] = min(dp[i][j],nums[i].second + dfs(i-1,j-1,dfs));
            }
        }

        return dp[i][j];
    };

    int mini = inf;

    for(int i=1;i<=n;i++)
        mini = min(mini,dfs(i,n-1,dfs));

    return mini;
}

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
       return ans(cost,time); 
    }
};