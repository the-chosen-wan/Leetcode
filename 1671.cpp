#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int mini(vector<int>& nums){
    int n = nums.size();
    vector<int> greater(n,1);

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i])
                greater[i] = max(greater[i],greater[j]+1);
        }
    }

    vector<int> lesser(n,1);

    for(int i=n-1;i>=0;i--){
        for(int j=n;j>i;j--){
            if(nums[j]<nums[i])
                lesser[i] = max(lesser[i],lesser[j]+1);
        }
    }

    int ret = -inf;
    for(int i=1;i<n-1;i++){
        if(greater[i]!=1&&lesser[i]!=1)
            ret = max(ret,greater[i]+lesser[i]-1);
    }
    return n-ret;
}

class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        return mini(nums);
    }
};