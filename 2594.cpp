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

ll ans(vector<int>& ranks, int cars) {
    int n = ranks.size();

    auto check = [&](ll val)->bool{
        ll cnt = 0;

        for(int i=0;i<n;i++){
            cnt+=floor(sqrt((double)(val)/(double)(ranks[i])));
        }

        return cnt>=cars;
    };

    ll high = 1e16;
    ll low = 0;

    while(low<=high){
        if(low==high-1||low==high){
            if(check(low))
                return low;
            return high;
        }

        ll mid = (low+high)/2;

        if(check(mid))
            high = mid;
        else
            low = mid+1;
    }
    return -1;
}

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        return ans(ranks,cars);
    }
};