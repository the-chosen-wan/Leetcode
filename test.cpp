#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);

    dp[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i] + ((i > 1) ? dp[i - 2] : 0);
        int notPick = dp[i - 1];

        dp[i] = max(pick, notPick);
    }

    return dp[n - 1];
}

int main(){
    vector<int> v = {2,7,9,3,1};
    cout<<rob(v)<<endl;
    return 0;
}
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        return rob(nums);
    }
};