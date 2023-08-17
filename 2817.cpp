#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair
const int N = (1e5)+1;

int ans(vector<int>& nums,int x){
    int n = nums.size();

    set<pii> setta;

    for(int i=n-1;i>=x;i--){
        setta.insert(mp(nums[i],i));
    }

    int mini = inf;

    for(int i=0;i<n;i++){
        if(i-x-1>=0){
            setta.insert(mp(nums[i-x-1],i-x-1));
        }

        if(i+x-1<n&&i+x-1>=0){
            setta.erase(mp(nums[i+x-1],i+x-1));
        }

        auto lower = setta.lower_bound(mp(nums[i],-inf));
        
        if(lower!=setta.end())
            mini = min(mini,abs(nums[i]-(*lower).first));

        if(lower!=setta.begin()){
            lower--;
            mini = min(mini,abs(nums[i]-(*lower).first));
        }
    }
    return mini;
}

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        return ans(nums,x);
    }
};