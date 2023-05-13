#include <iostream>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
#define N 16

int ans(vector<int> &nums)
{
    unordered_map<int, int> mappa;
    for (int i = 0; i < (1 << N); i++)
        mappa[i] = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            mappa[nums[i] & nums[j]]++;
    }

    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        int s = ((1 << N) - 1) ^ nums[i];
        while (s > 0)
        {
            c += mappa[s];
            s = (s - 1) & (((1 << N) - 1) ^ nums[i]);
        }
        tot += c;
        tot += mappa[0];
    }
    return tot;
}

// int main(){
//     vector<int> v = {2,1,3};
//     cout<<ans(v)<<endl;
//     return 0;
// }

class Solution
{
public:
    int countTriplets(vector<int> &nums)
    {
        return ans(nums);
    }
};