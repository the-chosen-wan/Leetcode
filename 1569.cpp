#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair
#define N 1001

int ans(vector<int> &nums)
{
    cout<<"Hi"<<endl;
    int dp[N][N];
    dp[0][0] = 1;
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = 1;
        dp[0][i] = 0;
    }

    for (int i = 1; i < N; i++)
        for (int j = 1; j < N; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % inf;

    int n = nums.size();

    auto dfs = [&](vector<int> v, auto &&dfs) -> ll
    {
        if (v.size() <= 1)
            return 1;

        vector<int> small;
        vector<int> large;
        int num = v[0];
        int s = v.size();
        for (int i = 1; i < s; i++)
        {
            if (v[i] < v[0])
                small.pb(nums[i]);
            else
                large.pb(nums[i]);
        }
        int sn = small.size();
        int sl = large.size();
        ll sret = dfs(small, dfs);
        ll lret = dfs(large, dfs);
        ll ret = (((sret * lret) % inf) * dp[s - 1][sn]) % inf;
        return ret;
    };
    ll ret = dfs(nums, dfs);
    return dp[2][0];
}

class Solution
{
public:
    int numOfWays(vector<int> &nums)
    {
        return ans(nums);
    }
};

int main(){
    vector<int> v = {1,2,3};
    cout<<ans(v)<<endl;
    return 0;
}