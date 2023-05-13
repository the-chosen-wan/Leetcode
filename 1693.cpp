#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int pref_sum(vector<int>&pref_array,int l,int r){
    if(l==0)
        return pref_array[r];
    return pref_array[r]-pref_array[l-1];
}

int maxscore(vector<int>& values){
    int n = values.size();
    vector<int> pref(n);
    pref[0] = values[0];

    for(int i=1;i<n;i++)    
        pref[i] = pref[i-1]+values[i];
    
    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int i=0;i<n;i++)
        dp[i][0] = values[i];
    
    for(int j=1;j<n;j++){
        for(int i=0;i<n;i++){
            int maxa = -inf;
            for(int k=i;k<j+i;k++){
                int sum1 = pref_sum(pref,i,k);
                int sum2 = pref_sum(pref,k+1,j+i);
                if(sum1>sum2)
                    maxa = max(maxa,sum2+dp[k+1][j+i]);
                else if(sum2>sum1)
                    maxa = max(maxa,sum1+dp[i][k]);
                else 
                    maxa = max(maxa,sum1+max(dp[i][k],dp[k+1][j+1]));
            }
        }
    }
    
    return dp[0][n-1];
}

class Solution
{
public:
    int stoneGameV(vector<int> &stoneValue)
    {
        return maxscore(stoneValue);
    }
};