#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<vector<int>> &fruits, int start, int k)
{
    int n = fruits.size();
    int sum = 0;
    vector<pii> nums;
    for (int i = 0; i < n; i++)
        nums.pb(mp(fruits[i][0], fruits[i][1]));
    int firstpos = -1;

    vector<pii> prefsum;
    for (int i = 0; i < n; i++)
    {
        if (nums[i].first < start)
            continue;
        if (firstpos == -1)
            firstpos = i - 1;
        sum += nums[i].second;
        prefsum.pb(mp(nums[i].first - start, sum));
    }

    int maxa = 0;
    sum = 0;
    int dist = 0;
    for (int i = firstpos; i >= 0; i--)
    {
        if (k - dist < 0)
            break;
        int ind = upper_bound(prefsum.begin(), prefsum.end(), mp(k - dist, inf)) - prefsum.begin() - 1;
        if (ind == -1)
            break;
        maxa = max(maxa, sum + prefsum[ind].second);
        sum += nums[i].second;
        dist = start - nums[i].first;
    }

    int ind = upper_bound(prefsum.begin(), prefsum.end(), mp(k, inf)) - prefsum.begin() - 1;
    if (ind != -1)
        maxa = max(maxa, prefsum[ind].second);

    return maxa;
}

// int main(){
//     vector<vector<int>> v = {{20000,10000}};
//     cout<<ans(v,20000,20000)<<endl;
//     return 0;
// }

class Solution
{
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        return ans(fruits, startPos, k);
    }
};