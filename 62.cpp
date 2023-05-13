#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(int m,int n){
    vector<vector<ll>> dp(m,vector<ll>(n,0));
    dp[0][0] = 1;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i!=0)
                dp[i][j]+=dp[i-1][j];
            if(j!=0)
                dp[i][j]+=dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        return ans(m,n);
    }
};