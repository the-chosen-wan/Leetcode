#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
using pii=pair<int,int>;
#define pb push_back
#define mp make_pair

int ans(vector<int>& nums){
    int n = nums.size();

    ll sum = 0;
    for(int i=0;i<n;i++)
        sum+=nums[i];

    if(sum%n!=0)
        return -1;
    
    int ans=0;
    ll val = sum/n;

    set<pii> valid;

    
}

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        return ans(machines);
    }
};