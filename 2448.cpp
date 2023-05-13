#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

ll ans(vector<int>& nums,vector<int>& cost){
    int n = nums.size();
    vector<pii> pa;

    for(int i=0;i<n;i++)
        pa.pb(mp(nums[i],cost[i]));
    
    sort(pa.begin(),pa.end());

    
}