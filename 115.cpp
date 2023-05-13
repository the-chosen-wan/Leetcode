#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define N (long long)1e12

ll minimum(string s1,string s2){
    ll l1 = s1.length();
    ll l2 = s2.length();
    ll dp[l1][l2];

    if(s1[0]==s2[0])
        dp[0][0] = 1;
    else 
        dp[0][0] =0;

    for(int i=1;i<l1;i++){
        dp[i][0] = 0;
        if (s1[i] == s2[0])
            dp[i][0]++;
        dp[i][0] += dp[i-1][0];
    }

    for(ll i=1;i<l2;i++){
        dp[0][i]=0;
    }

    for(int i=1;i<l1;i++){
        for(int j=1;j<l2;j++){
            dp[i][j]=0;
            if(s1[i]==s2[j])
                dp[i][j]= (dp[i][j]+dp[i-1][j-1])%N;
            dp[i][j]=(dp[i][j]+dp[i-1][j])%N;
        }
    }

    return dp[l1-1][l2-1];
}

class Solution
{
public:
    ll numDistinct(string s, string t)
    {
        return minimum(s,t);
    }
};

// ll main(){
//     string s1,s2;
//     cin>>s1>>s2;
//     cout<<minimum(s1,s2);
// }