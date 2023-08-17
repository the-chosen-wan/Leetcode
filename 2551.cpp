#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include<chrono>
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

ll ans(vector<int>& weights,int k){
    if(k==1)
        return 0;
    int n = weights.size();

    vector<int> pairsum;

    for(int i=0;i<n-1;i++){
        pairsum.pb(weights[i]+weights[i+1]);
    }

    sort(pairsum.begin(),pairsum.end());


    ll maxa = 0;
    ll mini = 0;

    for(int i=0;i<k-1;i++)
        mini+=pairsum[i];
    
    for(int i=n-2;i>=n-k;i--)
        maxa+=pairsum[i];
    

    return maxa-mini;
}

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        return ans(weights,k);
    }
};