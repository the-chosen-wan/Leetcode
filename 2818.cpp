#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair
const int N = (1e5)+1;

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

int ans(vector<int>& nums,int k){
    ll prod = 1LL;
    int n = nums.size();

    vector<int> primes(N,0);

    primes[1] = 0;
    
    for(int i=2;i<N;i++){
        if(primes[i]==0){
            primes[i]=1;

            for(int j=2*i;j<N;j+=i)
                primes[j]++;
        }
    }

    vector<pii> sorted;

    for(int i=0;i<n;i++)
        sorted.pb(mp(nums[i],i));

    
    sort(sorted.begin(),sorted.end(),greater<pii>());

    vector<int> prev(n,-1);
    vector<int> next(n,n);
    stack<pii> st;
    

    for(int i=0;i<n;i++){
        if(st.empty()){
            st.push(mp(primes[nums[i]],i));
        }

        else{
            while(!st.empty()&&st.top().first<primes[nums[i]])
                st.pop();
            
            if(!st.empty())
                prev[i] = st.top().second;
            
            st.push(mp(primes[nums[i]],i));
        }
    }

    while(!st.empty())
        st.pop();
    
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            st.push(mp(primes[nums[i]],i));
        }
        else{
            while(!st.empty()&&st.top().first<=primes[nums[i]])
                st.pop();
            
            if(!st.empty())
                next[i] = st.top().second;
            
            st.push(mp(primes[nums[i]],i));
        }
    }
    

    for(int i=0;i<n;i++){
        
        if(k==0)
            break;
        
        ll val = sorted[i].first;
        int ind = sorted[i].second;
        
        // cout<<val<<" "<<prev[ind]<<" "<<next[ind]<<endl;

        ll numarrays = (ll)(ind-prev[ind])*(next[ind]-ind);
        ll cnt = min<ll>(numarrays,k);
        k-=cnt;

        prod = (1LL*prod*binpow(val,cnt))%inf;
    }

    return prod;
}

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        return ans(nums,k);
    }
};
