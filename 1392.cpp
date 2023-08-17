#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair
const int  p =31;

ll binpow(ll a,ll b){
    ll res = 1;
    while(b>0){
        if(b&1)
            res = (res*a)%inf;
        a = (a*a)%inf;
        b>>=1;
    }
    return res;
}

ll inverse(ll a){
    return binpow(a,inf-2);
}

string ans(string s){
    int n = s.length();

    vector<ll> hash(n,0);
    ll ppow = 1;
    hash[0] = (ppow*(s[0]-'a'+1))%inf;

    for(int i=1;i<n;i++){
        ppow = (ppow*p)%inf;
        hash[i] = (hash[i-1] + ppow*(s[i]-'a'+1))%inf;
    }

    auto range = [&](int l,int r)->ll{
        if(l<=0)
            return hash[r];
        
        ll ret = ((hash[r]-hash[l-1])*inverse(binpow(p,l)))%inf;

        if(ret<0)
            ret+=inf;
        return ret;
    };

    int maxa = -1;

    for(int i=0;i<n-1;i++){
        if(range(0,i)==range(n-1-i,n-1)){
            maxa = i;
        }
    }

    if(maxa==-1)
        return "";
    
    return s.substr(0,maxa+1);
}

class Solution {
public:
    string longestPrefix(string s) {
        return ans(s);
    }
};
