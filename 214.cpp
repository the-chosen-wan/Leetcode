#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair
#define N ((1e5) + 1)
const int p = 31;

ll binpow(ll a,ll b){
    ll res = 1;
    
    while(b>0){
        if(b&1){
            res=(res*a)%inf;
        }
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
    vector<ll> hashes(n,0);

    ll ppow = 1;
    ll hash = 0;
    for(int i=0;i<n;i++){
        hash = (hash+(s[i]-'a'+1)*ppow)%inf;
        hashes[i] = hash;
        ppow = (ppow*p)%inf;
    }

    auto hashsub = [&](int l,int r)->ll{
        if(l==0)
            return hashes[r];
        
        ll val = ((hashes[r]-hashes[l-1])*inverse(binpow(p,l)))%inf;
        if(val<0)
            val+=inf;
        return val;
    };

    auto check = [&](int r)->bool{
        if(r&1){
            int mid = r/2;
            return hashsub(0,mid) == hashsub(mid+1,r);
        }
        else{
            if(r==0)
                return true;
            
            int mid1 = (r-1)/2;
            
        }
    };
}