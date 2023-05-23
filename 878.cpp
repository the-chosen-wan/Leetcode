#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9+7;
#define pb push_back
#define mp make_pair

int ans(ll n,ll a,ll b){
    ll lcm = (a*b)/(__gcd(a,b));

    auto findcnt = [&](ll i)->ll{
        return (i/a)+(i/b)-(i/lcm);
    };

    ll high = 1e16;
    ll low = 1;

    while(low<=high){
        if(low==high)
            return low%inf;
            
        if(low==high-1){
            if(findcnt(low)==n)
                return low%inf;
            return high%inf;
        }

        ll mid = (low+high)/2;

        ll num = findcnt(mid);

        if(num>=n)
            high = mid;
        else
            low=mid+1;
    }

    return -1;
}

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        return ans(n,a,b);
    }
};