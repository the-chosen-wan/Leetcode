#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

int ans(vector<int>& nums,int k){
    int n = nums.size();

    vector<int> bin(n,0);
    int ind;

    for(int i=0;i<n;i++){
        bin[i] = nums[i]>k;

        if(nums[i]==k)
            ind=i;
    }

    map<int,int> suff;
    int zeros = 0;
    int cnt = 0;

    for(int i=ind;i<n;i++){
        zeros+=(1-bin[i]);
        suff[i-ind+1 - 2*(zeros)]++;

        if(i-ind+1 == 2*zeros)
            cnt++;
        
        if(i-ind+1 == (2*zeros-1))
            cnt++;
    }

    zeros=0;
    for(int i=ind-1;i>=0;i--){
        zeros+=(1-bin[i]);

        int val = (ind-i) - 2*zeros;

        if(suff.find(-val)!=suff.end()){
            cnt+=suff[-val];
        }

        if(suff.find(-1-val)!=suff.end())
            cnt+=suff[-1-val];
    }

    return cnt;
}

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        return ans(nums,k);
    }
};