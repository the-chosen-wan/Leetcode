#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
const int N  =26;

int ans(){
    int n,m,k;
    cin>>n>>m>>k;
    k--;

    auto check = [&](ll val)->bool{
        ll maxval = (n-1)*val;
        ll left = 0;
        ll right = 0;

        if(val>=k+1){
            left = (k*val) - ((k)*(k+1))/2;
        }

        else{
            left = ((val)*(val-1))/2 + k-val+1;
        }

        if(val>=n-k){
            right = ((n-k-1)*val) - ((n-k-1)*(n-k))/2;
        }

        else{
            right = ((val)*(val-1))/2 + n-k-val;
        }

        ll minval = left+right;

        if(m-val>=minval&&m-val<=maxval)
            return true;
        return false;
    };

    ll low = ceil((double)m/(double)n);

    ll high = 1e10;

    while(low<=high){
        if(low+1==high||low==high){
            if(check(high))
                return high;
            return low;
        }

        ll mid  = (high+low)/2;

        if(check(mid))
            low=mid;
        else
            high=mid-1;
    }

    return -1;
}

int main(){
    cout<<ans()<<endl;
}