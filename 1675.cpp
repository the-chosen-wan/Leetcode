#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using namespace std;
const int inf = (1e9)+7;
#define pb push_back
#define mp make_pair


int ans(vector<int>& nums){
    int n = nums.size();
    priority_queue<ll> pqmax;
    ll mini = inf;

    for(int i=0;i<n;i++){

        if(nums[i]&1){
            pqmax.push(nums[i]<<1);
            mini = min<ll>(mini,nums[i]<<1);
        }
        else{
            pqmax.push(nums[i]);
            mini = min<ll>(mini,nums[i]);
        }
    }
    ll ans = pqmax.top()-mini;

    while(pqmax.top()%2==0){
        int y = pqmax.top();
        ans = min<ll>(ans,y-mini);
        pqmax.pop();
        pqmax.push(y/2);
        mini = min<ll>(mini,y/2);
    }

    int ret = pqmax.top()-mini;
    return min<ll>(ans,ret);
}

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        return ans(nums);
    }
};