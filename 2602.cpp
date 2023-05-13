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

vector<ll> ans(vector<int>& nums,vector<int>& queries){

    sort(nums.begin(),nums.end());
    int n = nums.size();
    int m = queries.size();


    vector<ll> prefsum(n,0);

    prefsum[0] = nums[0];

    for(int i=1;i<n;i++)
        prefsum[i]=prefsum[i-1]+nums[i];
    
    vector<ll> ans(m,0);

    auto sum = [&](int l,int r)->ll{
        if(l==0)
            return prefsum[r];
        return prefsum[r]-prefsum[l-1];
    };

    for(int i=0;i<m;i++){
        ll q = queries[i];

        auto it = lower_bound(nums.begin(),nums.end(),q);

        if(it==nums.begin()){
            ans[i] = sum(0,n-1) - n*q;
        }

        else{
            ll ind = it - nums.begin();

            ans[i]  = (ind*q-sum(0,ind-1))+(sum(ind,n-1)-(n-ind)*q);
        }
    }

    return ans;
}

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        return ans(nums,queries);
    }
};