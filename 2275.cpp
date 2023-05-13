#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define inf (int)((1e9) + 7)
#define pb push_back
#define mp make_pair
#define N 32

int ans(vector<int>& nums){
    int n  = nums.size();
    vector<int> dp(N,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<N;j++){
            if((nums[i]&(1<<j))!=0)
                dp[j]++;
        }
    }
    return *max_element(dp.begin(),dp.end());
}

class Solution
{
public:
    int largestCombination(vector<int> &candidates)
    {
        return ans(candidates);
    }
};