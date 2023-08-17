#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int ans(vector<int>& nums1,vector<int>& nums2){
    int n = nums1.size();
    int m = nums2.size();

    vector<vector<int>> dp(n,vector<int>(m,-inf));

    dp[0][0] = nums1[0]*nums2[0];
    int maxa = nums1[0]*nums2[0];

    for(int i=1;i<n;i++){
        dp[i][0] = max(dp[i-1][0],nums1[i]*nums2[0]);
        maxa= max(maxa,dp[i][0]);
    }
    
    for(int j=1;j<m;j++){
        dp[0][j] = max(dp[0][j-1],nums1[0]*nums2[j]);
        maxa = max(maxa,dp[0][j]);
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){

            dp[i][j] = max({dp[i-1][j], dp[i][j-1], nums1[i]*nums2[j] + dp[i-1][j-1],nums1[i]*nums2[j]});
            maxa = max(maxa,dp[i][j]);
        }
    }
    return maxa;
}

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        return ans(nums1,nums2);
    }
};