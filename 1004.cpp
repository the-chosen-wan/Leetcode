#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int>& nums,int k){
    int n = nums.size();
    vector<int> prefsum(n,0);

    prefsum[0] = nums[0];

    for(int i=1;i<n;i++)
        prefsum[i]=prefsum[i-1]+nums[i];

    auto query = [&](int l,int r)->int{
        if(l==0)
            return prefsum[r];
        return prefsum[r]-prefsum[l-1];
    };

    auto check = [&](int len)->bool{

        for(int i=0;i<=n-len;i++){
            int cntone = query(i,i+len-1);

            if(len-cntone<=k)
                return true;
        }

        return false;
    };

    int high = n;
    int low = 0;

    while(low<=high){
        if(low==high)
            return low;
        
        if(low+1==high){
            if(check(high))
                return high;
            return low;
        }

        int mid = (low+high)/2;

        if(check(mid))
            low=mid;
        else
            high=mid-1;
    }
    return -1;
}

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        return ans(nums,k);
    }
};

