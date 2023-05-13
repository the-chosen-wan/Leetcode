#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define inf (ll)((1e9) + 7)
#define pb push_back
#define mp make_pair

int ans(string s)
{
    int n = s.size();
    if (n == 0)
        return 0;
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == ')')
        {
            if (s[i - 1] == '(' && i >= 2)
                dp[i] = max(dp[i], 2 + dp[i - 2]);
            else
            {
                if (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(')
                    dp[i] = max(dp[i], 2 + dp[i - 1] + ((i - 2 - dp[i - 1] >= 0) ? dp[i - 2 - dp[i - 1]] : 0));
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

// int main(){
//     string s = "(()";
//     cout<<ans(s)<<endl;
// }

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        return ans(s);
    }
};