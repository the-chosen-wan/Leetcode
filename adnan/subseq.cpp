#include<iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include<chrono>
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair
const int N = 26;
const int L = 1e5;

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % inf;
        a = (a * a) % inf;
        b >>= 1;
    }
    return res;
}

ll inverse(ll a)
{
    return binpow(a, inf - 2);
}

ll ans(string s){
    vector<int> count(N,0);

    int n = s.size();

    for(int i=0;i<N;i++)
        count[s[i]-'a']++;

    vector<ll> fact(L+1,1);

    for(int i=2;i<=L;i++)
        fact[i] = (fact[i-1]*i)%inf;
    
    auto nck = [&](int n,int k)->ll{
        ll ans = (fact[n]*((inverse(fact[k])*inverse(fact[n-k]))%inf));
        return ans;
    };

    ll ret = 0;

    sort(count.begin(),count.end());

    for(int i=0;i<N;i++){
        if(count[i]==0)
            continue;
        
        ll prod = 1;

        if(i!=0&&count[i]==count[i-1])
            continue;
        
        for(int j=i;j<N;j++){
            prod = (prod*(nck(count[j],count[i])+1))%inf;
        }
        ret = (ret+prod-1)%inf;
    }
    if(ret<0)
        ret+=inf;
    return ret;
}

int main(){
    string s;cin>>s;
    cout<<ans(s)<<endl;
}