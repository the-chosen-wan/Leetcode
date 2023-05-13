#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int ans(int n)
{
    vector<int> digits;
    int num = 0;
    while (n != 0)
    {
        digits.pb(n % 10);
        n /= 10;
        num++;
    }
    vector<vector<vector<vector<int>>>> dp(num, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(1 << 10, -1))));

    auto dfs = [&](int pos, int flag, int zero_flag, int mask, auto &&dfs) -> int
    {
        if (pos < 0)
        {
            if (zero_flag == 1)
                return 1;
            return 0;
        }
        if (dp[pos][flag][zero_flag][mask] != -1)
            return dp[pos][flag][zero_flag][mask];

        int ret = 0;
        int k = flag == 1 ? 9 : digits[pos];
        for (int i = 0; i <= k; i++)
        {
            int new_flag = flag == 1 ? flag : (i < digits[pos]);
            if (zero_flag == 0 && i == 0)
                ret += dfs(pos - 1, new_flag, 0, mask, dfs);
            else
            {
                if ((mask & (1 << i)) != 0)
                    ret += dfs(pos - 1, new_flag, 1, mask ^ (1 << i), dfs);
            }
        }
        dp[pos][flag][zero_flag][mask] = ret;
        return ret;
    };
    return dfs(num - 1, 0, 0, (1 << 10) - 1, dfs);
}

class Solution
{
public:
    int countSpecialNumbers(int n)
    {
        return ans(n);
    }
};

int main(){
    int n = 20;
    cout<<ans(n)<<endl;
    return 0;
}