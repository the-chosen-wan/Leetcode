#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

ll ans(vector<int>& nums){
    ll tot=0;
    ll low = 0;
    ll high = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]!=0){
            ll val = (high-low+1)*(high-low)/2;
            tot+=val;
            high = i+1;
            low = i+1;
        }
        else{
            high=i;
        }
    }
    return tot;
}

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        return ans(nums);
    }
};