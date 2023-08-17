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

bool ans(vector<int>& nums,int k){
    int n = nums.size();
    vector<int> subarray(n,0);
    subarray[0] = nums[0];

    int prefsum = nums[0];

    if(n==1||k==1)
        return true;
    
    for(int i=1;i<n;i++){
        subarray[i] = nums[i] - prefsum;

        if(subarray[i]<0)
            return false;
        
        prefsum+=subarray[i];

        if(i>=k-1)
            prefsum-=subarray[i-k+1];
        
        if(i>=n-k+1&&subarray[i]!=0)
            return false;
    }

    return true;
}

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        return ans(nums,k);
    }
};