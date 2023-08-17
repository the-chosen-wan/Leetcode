#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair
#define mt make_tuple

int ans(vector<int>& nums){
    int n = nums.size();
    vector<ll> prefsum(n,0);
    vector<ll> prodsum(n,0);
    vector<ll> squaresum(n,0);

    prefsum[0] = nums[0];
    
    for(int i=1;i<n;i++){
        prefsum[i] = (prefsum[i-1]+nums[i])%inf;
        ll val1 = ((ll)i*nums[i]);
        prodsum[i] = (prodsum[i-1] + val1)%inf;
        ll val = (((ll)i*i))%inf;
        squaresum[i] = (squaresum[i-1] + val*nums[i])%inf;
    }

    stack<pii> prevst;
    stack<pii> nextst;

    vector<int> prev(n,-1);
    vector<int> next(n,n);

    for(int i=0;i<n;i++){
        if(prevst.empty()){
            prevst.push(mp(i,nums[i]));
        }

        else{
            
            while(!prevst.empty()&&prevst.top().second>=nums[i]){
                prevst.pop();
            }

            if(!prevst.empty()){
                prev[i] = prevst.top().first;
            }
            prevst.push(mp(i,nums[i]));
        }
    }

    for(int i=n-1;i>=0;i--){
        if(nextst.empty()){
            nextst.push(mp(i,nums[i]));
        }

        else{
            
            while(!nextst.empty()&&nextst.top().second>nums[i]){
                nextst.pop();
            }

            if(!nextst.empty()){
                next[i] = nextst.top().first;
            }
            nextst.push(mp(i,nums[i]));
        }
    }


    auto range = [&](int l,int r,vector<ll>& arr)->ll{
        if(l<=0)
            return arr[r];
        
        ll ret = (arr[r]-arr[l-1])%inf;

        if(ret<0)
            ret+=inf;
        return ret;
    };

    auto getvalue = [&](int x,int y,int val)->ll{
        if(x>=y||x+1==y)
            return 0;
        ll val1 = ((x+y)*range(x+1,y-1,prodsum))%inf;
        ll val2 = range(x+1,y-1,squaresum);
        ll val3 = ((((ll)x*y)%inf)*range(x+1,y-1,prefsum))%inf;
        ll val4 = (val1-val2-val3)%inf;

        if(val4<0)
            val4+=inf;
        
        return ((val*val4))%inf;
    };
  
    
    ll ans = 0;


    for(int i=0;i<n;i++){
        int x = prev[i];
        int y = next[i];
        int val = nums[i];
        int ind = i;

        ll ret = 0;
        ret = (getvalue(x,y,val) - getvalue(x,ind,val) - getvalue(ind,y,val))%inf;

        if(ret<0)
            ret+=inf;
        ans = (ans+ret)%inf;
    }
    return ans;

}

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        return ans(strength);
    }
};