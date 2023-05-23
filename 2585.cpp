#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

int ans(int target,vector<vector<int>>& types){
    int n = types.size();

    vector<vector<ll>> dp(target+1,vector<ll>(n+1,0));

    for(int i=0;i<=n;i++)
        dp[0][i] = 1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            int cnt = types[i-1][0];
            int marks = types[i-1][1];

            dp[j][i] = dp[j][i-1];

            for(int k=1;k<=cnt;k++){
                if(j-k*marks>=0){
                    dp[j][i] = (dp[j][i]+dp[j-k*marks][i-1])%inf;
                }
                else
                    break;
            }
        }
    }

    return dp[target][n];
}

class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        return ans(target,types);
    }
};