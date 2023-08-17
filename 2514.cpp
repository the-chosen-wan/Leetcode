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



int ans(string s) {
    vector<ll> fact(N,1);

    for(int i=1;i<N;i++){
        fact[i] = (fact[i-1]*i)%inf;
    }

    auto check = [&](string s)->ll{
        vector<int> alph(26,0);

        int n=s.size();

        for(int i=0;i<n;i++){
            alph[s[i]-'a']++;
        }
        ll ret = fact[n];

        for(int i=0;i<26;i++){
            if(alph[i])
                ret  = (ret*inverse(fact[alph[i]]))%inf;
        }
        return ret;
    };

    ll ans = 1;

    string word;
    istringstream ss(s);

    while(ss >> word) {
        ans = (ans*check(word))%inf;
    }
    return ans;
}

class Solution {
public:
    int countAnagrams(string s) {
        return ans(s);
    }
};