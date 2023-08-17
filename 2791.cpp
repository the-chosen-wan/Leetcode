#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using namespace std;
const int inf = (1e9)+7;
#define pb push_back
#define mp make_pair

ll ans(vector<int>& parent,string s){
    using pcc = pair<int,char>;
    int n = parent.size();
    vector<vector<pcc>> adj(n);

    for(int i=1;i<n;i++){
        adj[parent[i]].pb(mp(i,s[i]));
        adj[i].pb(mp(parent[i],s[i]));
    }

    map<ll,ll> cnt;
    ll mask=0;

    auto dfs = [&](int src,int par,auto&& dfs)->void{
        cnt[mask]++;

        for(pcc v:adj[src]){
            if(v.first!=par){
                mask^=(1<<(v.second-'a'));
                dfs(v.first,src,dfs);
                mask^=(1<<(v.second-'a'));
            }
        }
        return;
    };
    dfs(0,0,dfs);

    const int N = 26;

    ll ans = 0;

    for(pair<ll,ll> v:cnt){
        ans+=((v.second-1)*v.second)/2;
    }

    ll ans1 = 0;

    for(int i=0;i<N;i++){
        ll mask = (1LL<<i);
        for(pair<ll,ll> v:cnt){
            ll val = v.second;
            ll num = v.first;

            if(cnt.find(num^mask)!=cnt.end()){
                ans1+=(val*cnt[num^mask]);
            }
        }
    }
    ans1/=2;
    return ans+ans1;
}

class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        return ans(parent,s);
    }
};