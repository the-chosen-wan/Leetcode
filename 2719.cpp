#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include<chrono>
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

ll calculateDp(vector<int>& num,int max1,int max2){
    int n = num.size();
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(2,vector<ll>(9*n+1,-1)));
    ll ans = 0;
    auto dfs = [&](int ind,int tight,int sum,auto&& dfs)->ll{
        if(ind==n){
            if(sum>=max1&&sum<=max2){
                return 1;
            }
            return 0;
        }

        if(dp[ind][tight][sum]!=-1)
            return dp[ind][tight][sum];
        
        int newtight;
        
        int limit = tight==1?9:num[ind];

        ll ret = 0;

        for(int i=0;i<=limit;i++){
            int newtight = i<limit?1:tight;

            ret = (ret+dfs(ind+1,newtight,sum+i,dfs))%inf;
        }

        dp[ind][tight][sum] = ret;
        return ret;
    };
    
    return dfs(0,0,0,dfs);
}

int ans(string num1,string num2,int max1,int max2){
    int n1 = num1.size();
    int n2 = num2.size();
    int summa = 0;

    vector<int> k1;
    vector<int> k2;

    for(int i=0;i<n1;i++){
        k1.pb(num1[i]-'0');
        summa+=(num1[i]-'0');
    }
    
    for(int i=0;i<n2;i++){
        k2.pb(num2[i]-'0');
    }

    ll ans1 = calculateDp(k1,max1,max2);
    ll ans2 = calculateDp(k2,max1,max2);
    
    ll ans = (ans2-ans1+((summa>=max1)&&(summa<=max2)))%inf;
    if(ans<0)
        ans+=inf;
    return ans;
}

class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        return ans(num1,num2,min_sum,max_sum);
    }
};