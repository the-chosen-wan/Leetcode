#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
const int N = (1e5)+1;
#define pb push_back
#define pf push_front
#define mp make_pair

int ans(int div1,int div2,ll u1,ll u2) {
    ll lcm = ((ll)div1*(ll)div2)/(__gcd(div1,div2));

    ll high = 1e12;
    ll low = 0;

    auto check = [&](ll x)->bool{
        ll divByFirst = (x/div2) - (x/lcm);
        ll divBySecond = (x/div1) - (x/lcm);
        ll free = x - divByFirst - divBySecond - (x/lcm);
        
        if(divByFirst>=u1&&free+divBySecond>=u2)
            return true;
        else if(divBySecond>=u2&&free+divByFirst>=u1)
            return true;
        else if(divByFirst<u1&&divBySecond<u2&&((u1+u2)<=(free+divByFirst+divBySecond)))
            return true;
        return false;
    };
    while(low<=high) {
        if(low==high-1||low==high){
            if(check(low))
                return low;
            return high;
        }

        ll mid = (high+low)/2;
        if(check(mid))
            high = mid;
        else
            low=mid+1;
    }

    return -1;
}

class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        return ans(divisor1,divisor2,uniqueCnt1,uniqueCnt2);
    }
};