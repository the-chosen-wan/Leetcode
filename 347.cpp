#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

vector<int> ans(vector<int>& nums,int k){
    map<int,int> mappa;
    int n = nums.size();
    for(int i=0;i<n;i++)
        mappa[nums[i]]++;
    set<pii,greater<pii>> s;
    for(pii m:mappa)
        s.insert(mp(m.second,m.first));
    vector<int> ans;
    int c = 0;
    auto it = s.begin();
    while(c<k){
        ans.pb(it->second);
        c++;
        it++;
    }
    return ans;
}

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        return ans(nums,k);
    }
};