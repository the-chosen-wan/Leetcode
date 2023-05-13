#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9)+7);
#define pb push_back
#define mp make_pair

int ans(vector<int>& nums,int k){
    int n = nums.size();
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++)
        pq.push(nums[i]);

    ll ans = 1;
    while(k--){
        int top=pq.top();
        pq.pop();top++;
        pq.push(top);
    }

    while(!pq.empty()){
        int top = pq.top();
        ans = (ans*top)%inf;
        pq.pop();
    }
    return ans;
}

class Solution
{
public:
    int maximumProduct(vector<int> &nums, int k)
    {
        return ans(nums,k);
    }
};