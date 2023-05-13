#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

vector<int> ans(vector<int>& nums,vector<int>& queries){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<int> pref(n,0);
    pref[0]=nums[0];

    for(int i=1;i<n;i++)
        pref[i]=pref[i-1]+nums[i];
    
    int q=queries.size();
    vector<int> ans;

    for(int& k:queries){
        int num=upper_bound(pref.begin(),pref.end(),k)-pref.begin();
        ans.pb(num);
    }
    return ans;
}

class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        return ans(nums,queries);
    }
};