#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair
#define N 26

ll ans(vector<int> &nums)
{
    int n = nums.size();
    map<ll,int> s;
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            s[nums[i]]++;
            continue;
        }
        auto val = (--s.end());
        while (!s.empty() && val->first > nums[i])
        {
            if (val->first % nums[i] == 0)
            {
                sum += val->second*((val->first / nums[i]) - 1);
                s[val->first % nums[i]]++;
                s[nums[i]] += val->second * ((val->first / nums[i]) - 1);
            }
            else
            {
                sum += val->second*(val->first / nums[i]);
                s[nums[i]] += val->second * (val->first / nums[i]);
            }
            s.erase(val);
            val = (--s.end());
        }
        s[nums[i]]++;
    }
    return sum;
}

class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        return ans(nums);
    }
};

int main(){
    vector<int> v = {3,9,3};
    cout<<ans(v)<<endl;
    return 0;
}