#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool ans(string s, string p){
    int n = s.length();
    int m = p.length();

    vector<vector<bool>> dp(n,vector<bool>(m,false));
    bool flag1 = false;
    bool flag2 = false;

    if(p[m-1]=='?'||p[m-1]=='*'||p[m-1]==s[n-1])
        {dp[n-1][m-1]=true;flag1=true;}

    for(int i=m-2;i>=0;i--){
        flag2 = flag1;
        for(int j=n-1;j>=0;j--){
            if(p[i]=='?')
                {if(i==n-1)dp[j][i]=true;else dp[j][i] = dp[j+1][i+1];}
            else if(p[i]=='*')
                {dp[i][j]=flag2;}
            
        }
    }
}