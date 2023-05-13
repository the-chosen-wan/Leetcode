#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9)+7);
#define pb push_back
#define mp make_pair

int ans(int n){
    vector<ll> dp(n+1,0);
    dp[0]=0;
    dp[1] = 1;
    if(n>=2)
        dp[2] = 
}