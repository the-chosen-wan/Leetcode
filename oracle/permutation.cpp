#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9)+7;
#define pb push_back
#define mp make_pair
const int N  =26;
const int MAX = (1e4)+1;

ll binpow(ll a, ll b){
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

ll ans(string s){
    int n = s.length();

    vector<ll> fact(MAX,1);

    for(int i=1;i<MAX;i++){
        fact[i] = (i*fact[i-1])%inf;
    }

    auto nck = [&](int n,int k)->ll{
        ll denom = (inverse(fact[n-k])*inverse(fact[k]))%inf;
        ll ans = (fact[n]*denom)%inf;
        return ans;
    };

    vector<int> cnt(N,0);

    for(int i=0;i<n;i++)
        cnt[s[i]-'a']++;
    
    vector<int> pos;

    for(int i=0;i<N;i++){
        if(cnt[i]>0)
            pos.pb(cnt[i]);
    }

    int len = pos.size();

    vector<vector<ll>> dp(len,vector<ll>(n+1,0));

    dp[0][0] = 1;

    for(int i=1;i<=pos[0];i++){
        dp[0][i]=1;
    }

    for(int i=1;i<len;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=min(j,pos[i]);k++){
                dp[i][j] = (dp[i][j]+ dp[i-1][j-k]*nck(j,k))%inf;
            }
        }
    }
    
    ll ret = 0;

    for(int i=0;i<=n;i++){
        ret = (ret+dp[len-1][i])%inf;
    }

    return ret;
}

int main(){
    string s;cin>>s;
    cout<<ans(s)<<endl;
}