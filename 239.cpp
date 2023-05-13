#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair

vector<int> sliding(vector<int>& nums,int k){
    int len = nums.size();
    deque<pii> q;
    vector<int> result(len-k+1);

    int i=0;

    while(i<k){
        while(!q.empty()&&q.back().first<nums[i])
            q.pop_back();
        q.push_back(mp(nums[i],i));
        i++;
    }

    while(i<len){
        result[i-k]=q.front().first;
        if(q.front().second==i-k)
            q.pop_front();
        while(!q.empty()&&q.back().first<nums[i])
            q.pop_back();
        q.push_back(mp(nums[i],i));
        i++;   
    }
    result[len-k] = q.front().first;
    return result;
}

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        return sliding(nums,k);
    }
};