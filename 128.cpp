#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int>& nums){
    int n = nums.size();
    unordered_set<int> mappa;

    for(int i=0;i<n;i++)
        mappa.insert(nums[i]);
    
    
}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        return ans(nums);
    }
};