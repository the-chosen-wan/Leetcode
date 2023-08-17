#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

const int p = 31;

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

int ans(string s){
    int n = s.size();


    vector<ll> hash(n,0);

    ll ppow=1;

    hash[0] = (ppow*(s[0]-'a'+1))%inf;
    ppow = p;
    for(int i=1;i<n;i++){
        hash[i] = (hash[i-1]+ ppow*(s[i]-'a'+1))%inf;
        ppow = (ppow*p)%inf;
    }

    auto range = [&](int l,int r)->ll{
        if(l<=0)
            return hash[r];
        
        ll ret = ((hash[r]-hash[l-1])*inverse(binpow(p,l)))%inf;

        if(ret<0)
            ret+=inf;
        return ret;
    };

    ll low=0;
    ll high=n-1;

    int globalow=0;
    int globalhigh=n-1;

    int cnt=1;
    bool once = false;

    while(low<=high){
        ll hash1 = range(globalow,low);
        ll hash2 = range(high,globalhigh);

        if(hash1==hash2){
            once = true;
            if(low+1==high||low==high){
                cnt+=1;

                if(low+1==high)
                    cnt++;
            }
            else
                cnt+=2;
            globalow=low+1;
            globalhigh=high-1;
            low=globalow;
            high=globalhigh;
        }

        else{
            once=false;
            low++;
            high--;
        }
    }
    
    if(once)
        cnt--;
    
    return cnt;
}

class Solution {
public:
    int longestDecomposition(string text) {
        return ans(text);
    }
};