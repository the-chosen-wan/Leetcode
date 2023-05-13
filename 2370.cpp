#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair
#define N 26

int ans(string s, int k)
{
    int n = s.size();
    vector<int> dp(N, -inf);
    auto dist = [](int x, int y) -> int
    {
        return max(x - y, y - x);
    };

    for (int i = 0; i < n; i++)
    {
        dp[s[i]-'a']++;
        for (int j = 0; j < N; j++)
        {
            if (dist(s[i] - 'a', j) <= k&&s[i]-'a'!=j)
                dp[s[i] - 'a'] = max(dp[s[i] - 'a'], dp[j] + 1);
        }
        dp[s[i] - 'a'] = max(dp[s[i] - 'a'], 1);
        //cout<<s[i]<<" "<<dp[s[i]-'a']<<endl;
    }
    return *max_element(dp.begin(), dp.end());
}

class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        return ans(s, k);
    }
};

int main(){
    string s = "acfgbd";
    cout<<ans(s,2)<<endl;
    return 0;
}