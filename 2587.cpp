#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

int ans(vector<int>& nums){
    sort(nums.begin(),nums.end(),greater<int>());

    int ans=0;
    ll summa = 0;

    int n = nums.size();

    for(int i=0;i<n;i++){
        summa+=nums[i];

        if(summa>0)
            ans++;
        
        else
            return ans;
    }

    return ans;
}

class Solution {
public:
    int maxScore(vector<int>& nums) {
        return ans(nums);
    }
};