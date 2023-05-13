#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// using int=long long;
#define M (int)(1e9 + 7)

int inverse(int n, int k)
{
    vector<vector<int>> dp;
    dp.resize(n + 1, vector<int>(k + 1, 0));

    vector<vector<int>> pref;
    pref.resize(n + 1, vector<int>(k + 1, 0));

    // dp[1][0]=1;pref[1][0]=1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
        pref[i][0] = 1;
    }

    // for(int i=0;i<=k;i++)
    //     dp[1][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = j >= i ? (pref[i - 1][j] - pref[i - 1][j - i]) % M : (pref[i - 1][j]);
            if (dp[i][j] < 0)
                dp[i][j] += M;
            if (j >= 1)
                pref[i][j] = (pref[i][j - 1] + dp[i][j]) % M;
        }
    }
    return dp[n][k];
}

// int main(){
//     int n,k;cin>>n>>k;
//     cout<<inverse(n,k);
// }

class Solution
{
public:
    int kInversePairs(int n, int k)
    {
        return inverse(n, k);
    }
};