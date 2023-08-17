#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int ans(vector<vector<int>>& pairs){
    int n = pairs.size();
    vector<pii> pp;
    
    for(int i=0;i<n;i++){
        pp.pb(mp(pairs[i][0],pairs[i][1]));
    }

    sort(pp.begin(),pp.end());
    vector<int> dp(n,-1);

    dp[n-1] = 1;
    int maxa = 1;
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++)
            if(pp[j].first>pp[i].second)
                dp[i] = max(dp[i],dp[j]+1);

        if(dp[i]<=0)
            dp[i]=1;
        maxa = max(maxa,dp[i]);
    }

    return maxa;
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        return ans(pairs);
    }
};