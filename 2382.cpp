#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

void initialize(int n, vector<int> &parent)
{
    parent.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    return;
}

int find_sets(int v, vector<int> &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_sets(parent[v], parent);
}


vector<ll> ans(vector<int>& nums,vector<int>& queries){
    int q = queries.size();
    reverse(queries.begin(),queries.end());
    int n = nums.size();
    vector<int> copy(nums);

    
    for(int i=0;i<n;i++){
        nums[i]=0;
    }

    vector<int> parent;
    vector<ll> maxsum(n,0);
    ll ans = 0;

    initialize(n,parent);

    vector<ll> arr;
    arr.pb(0);

    for(int i=0;i<q;i++){
        int ind = queries[i];

        ll sumprev = 0;
        ll sumnext = 0;

        if(ind>0&&nums[ind-1]>0){
            sumprev = maxsum[find_sets(ind-1,parent)];
            parent[find_sets(ind-1,parent)] = ind;
        }
        if(ind<n-1&&nums[ind+1]>0){
            sumnext = maxsum[find_sets(ind+1,parent)];
            parent[ind] = find_sets(ind+1,parent);
        }

        maxsum[find_sets(ind,parent)] = sumprev+sumnext + copy[ind];
        ans = max<ll>(ans,sumprev+sumnext + copy[ind]);
        arr.pb(ans);
        nums[ind] = copy[ind];
    }

    arr.pop_back();
    reverse(arr.begin(),arr.end());
    return arr;
}

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        return ans(nums,removeQueries);
    }
};