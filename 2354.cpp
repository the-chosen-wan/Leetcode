#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
#define N 33

ll ans(vector<int> &nums, int k)
{
    ll tot = 0;
    int n = nums.size();
    unordered_set<int> contains;
    for (int i = 0; i < n; i++)
    {
        if(contains.find(nums[i])!=contains.end())
            continue;
        if (2 * (__builtin_popcount(nums[i])) >= k)
            tot++;
        contains.insert(nums[i]);
    }
    vector<ll> dp(N, 0);
    unordered_set<int> s(nums.begin(), nums.end());
    nums.clear();
    for (int k : s)
        nums.pb(k);
    n = nums.size();
    for (int i = 0; i < n; i++)
    {
        dp[__builtin_popcount(nums[i])]++;
    }


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i + j >= k)
            {
                if (i == j)
                    tot += (dp[i] * (dp[i] - 1));
                else
                    tot += (dp[i] * dp[j]);
            }
        }
    }
    return tot;
}

// int main(){
//     int k=2;
//     vector<int> v = {1,2,4,8,16,32,64,128,256};
//     cout<<ans(v,k)<<endl;
//     return 0;
// }

class Solution
{
public:
    long long countExcellentPairs(vector<int> &nums, int k)
    {
        return ans(nums, k);
    }
};