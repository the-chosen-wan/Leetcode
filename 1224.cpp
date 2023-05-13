#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums)
{
    nums.pb(inf);
    int n = nums.size();
    unordered_map<int, int> s;
    multiset<int> m;
    // for (int i = 0; i < n; i++)
    //     s[nums[i]] = 0;
    int ret = 1;

    for (int i = 0; i < n; i++)
    {
        if (!m.empty())
        {
            int mini = *m.begin();
            int maxa = *(--m.end());
            int s1 = m.size();
            int c = m.count(maxa);
            int siz = s.size();

            if (mini + 1 == maxa && c == 1)
                ret = i;
            if (mini == 1 && c == s1 - 1)
                ret = i;
            if (mini == 1 && maxa == 1)
                ret = i;
            if (siz == 1)
                ret = i;
        }
        auto it = m.find(s[nums[i]]);
        if (it != m.end())
            m.erase(it);
        s[nums[i]]++;
        m.insert(s[nums[i]]);
    }
    return ret;
}

// int main(){
//     vector<int> v = {2,2,1,1,5,3,3,5};
//     cout<<ans(v)<<endl;
//     return 0;
// }

class Solution
{
public:
    int maxEqualFreq(vector<int> &nums)
    {
        return ans(nums);
    }
};