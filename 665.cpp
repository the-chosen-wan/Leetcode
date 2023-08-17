#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair


bool ans(vector<int>& nums){
    int n = nums.size();
    vector<bool> pref;

    pref[0] = true;

    for(int i=1;i<n;i++){
        if(!pref[i-1])
            pref[i]=false;
        else{
            if(nums[i-1]>nums[i])
                pref[i] = false;
        }
    }

    for(int i=1;i<n;i++){
        if(nums[i-1]>nums[i]&&!pref[i-1])
            return false;
    }

    return true;
}

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        return ans(nums);
    }
};