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
// Common file



ll ans(vector<int>& nums){
    int n = nums.size();
    unordered_map<int,int> mappa;
    vector<pii> modnums;

    for(int i=0;i<n;i++){
        modnums.pb(mp(i,nums[i]));
    }

    sort(modnums.begin(),modnums.end(),[](pii& a,pii& b)->bool{
        return a.second<b.second;
    });

    // for(int i=0;i<n;i++){
    //     cout<<modnums[i].first<<" "<<modnums[i].second<<endl;
    // }
    

    vector<int> dp(n,0);


    for(int i=1;i<n;i++){
        if(modnums[i-1].first<modnums[i].first)
            dp[i] = dp[i-1];
        else
            dp[i]=dp[i-1]+1;
    }

    ll ans = 0;
    for(int i=0;i<n;i++)
        ans+=dp[i];
    return ans+n;
}

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        return ans(nums);
    }
};