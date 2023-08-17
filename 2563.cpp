#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

ll ans(vector<int>& nums,int lower,int upper){
    int n = nums.size();
    sort(nums.begin(),nums.end());

    int low1 = 0;int low2=0;
    ll ans=0;
    for(int i=1;i<n;i++){
        int ind = lower_bound(nums.begin(),nums.begin()+i,lower-nums[i]) - nums.begin();
        int ind1= upper_bound(nums.begin(),nums.begin()+i,upper-nums[i]) - nums.begin() - 1;
        ans+=(ind1-ind+1);
    }

    return ans;
}

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        return ans(nums,lower,upper);
    }
};