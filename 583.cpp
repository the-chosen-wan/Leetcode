#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

int ans(string word1,string word2){
    int n1 = word1.size();
    int n2 = word2.size();

    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(word1[i-1]==word2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return n1+n2-2*dp[n1][n2];
}

class Solution {
public:
    int minDistance(string word1, string word2) {
        return ans(word1,word2);
    }
};