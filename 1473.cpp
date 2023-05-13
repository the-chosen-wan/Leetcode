#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int>& houses,vector<vector<int>>& cost,int m, int n,int target){
    int dp[m][n][target+1];

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<=target;k++)
                dp[i][j][k] = inf;
    
    for(int i=0;i<n;i++)
        dp[0][i][0]=1;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
        }
    }
}