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

int ans(vector<int>& nums) {
    int n = nums.size();

    auto check = [&](ll k)->bool{
        ll summa = 0;
        for(int i=0;i<n;i++)
            summa+=min<ll>(nums[i],k);
        
        return summa>=((k*(k+1))/2);
    };

    ll low=0;
    ll high=0;

    while(low<=high) {
        if(low==high||low+1==high){
            if(check(high))
                return high;
            return low;
        }

        ll mid = (high+low)/2;

        if(check(mid))
            low=mid;
        else
            high=mid-1;
    }
    return -1;
}

class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        return ans(usageLimits);
    }
};