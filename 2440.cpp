#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

int ans(vector<int>& nums,vector<vector<int>>& edges){
    int n = nums.size();
    vector<vector<int>> adj(n);

    for(vector<int>& e:edges){
        adj[e[0]].pb(e[1]);
        adj[e[1]].pb(e[0]);
    }

    int sum = accumulate(nums.begin(),nums.end(),0);

    vector<int> div;
    int upper = ceil(sqrt(sum));

    for(int i=1;i<=upper;i++){
        if(sum%i==0){
            div.pb(i);
            div.pb(sum/i);
        }
    }

    sort(div.begin(),div.end(),greater<int>());

    auto check = [&](int par,int src,int val,auto&& check)->int{
        int s = 0;
        s+=nums[src];

        for(int v:adj[src]){
            if(v!=par){
                s+=check(src,v,val,check);
            }
        }

        if(s==val)
            return 0;
        return s;
    };

    for(int d:div){
        if(check(0,0,sum/d,check)==0)
            return d-1;
    }

    return 0;
}

class Solution
{
public:
    int componentValue(vector<int> &nums, vector<vector<int>> &edges)
    {
        return ans(nums,edges);
    }
};