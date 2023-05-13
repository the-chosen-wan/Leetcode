#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair
#define N 500
#define max_pref 50

int dp[N][max_pref][2][2];

int recurse(int pos, int pref, int tight1, int tight2, string &s1, string &s2, string &evil)
{
    if (pref == evil.length())
        return 0;
    if (pos == s1.length())
        return 1;

    if (dp[pos][pref][tight1][tight2] != -1)
        return dp[pos][pref][tight1][tight2];

    int k1 = tight1 ? 97 : s1[pos];
    int k2 = tight2 ? 122 : s2[pos];
    int len = evil.length();
    int ret = 0;

    for (int i = k1; i <= k2; i++)
    {
        char c = i;
        int check = (evil[pref] == c) ? pref + 1 : 0;
        int new_tight1, new_tight2;
        new_tight2 = (c < s2[pos]) ? 1 : 0;
        new_tight1 = (c > s1[pos]) ? 1 : 0;
        ret = (ret + recurse(pos + 1, check, new_tight1, new_tight2, s1, s2, evil)) % inf;
    }
    dp[pos][pref][tight1][tight2] = ret;
    return ret;
}

int give(string s1, string s2, string evil)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < max_pref; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    dp[i][j][k][l] = -1;
    return recurse(0, 0, 0, 0, s1, s2, evil);
}

class Solution
{
public:
    int findGoodStrings(int n, string s1, string s2, string evil)
    {
        return give(s1, s2, evil);
    }
};

// int main(){
//     string s1,s2,evil;
//     cin>>s1>>s2>>evil;
//     cout<<give(s1,s2,evil);
// }