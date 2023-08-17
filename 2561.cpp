#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
using pii=pair<int,int>;
#define pb push_back
#define mp make_pair

ll ans(vector<int>& nums1,vector<int>& nums2){
    int n = nums1.size();
    unordered_map<int,int> cnt;
    unordered_map<int,int> cnt1;
    unordered_map<int,int> cnt2;

    for(int i=0;i<n;i++){
        cnt[nums1[i]]++;
        cnt[nums2[i]]++;
        cnt1[nums1[i]]++;
        cnt2[nums2[i]]++;
    }

    for(pii p:cnt){
        if(p.second&1)
            return -1;
    }

    priority_queue<pii,vector<pii>,greater<pii>> pii1;
    priority_queue<pii> pii2;
    int mini = inf;

    for(pii p:cnt){
        int val1 = p.second;
        int val2 = cnt1[p.first];

        if(val2>val1/2){
            pii1.push(mp(p.first,val2-(val1/2)));
            cout<<1<<" "<<val2-(val1/2)<<endl;
        }
        else{
            mini = min(mini,p.first);
        }

        val2 = cnt2[p.first];
        if(val2>val1/2){
            pii2.push(mp(p.first,val2-(val1/2)));
            cout<<2<<" "<<val2-(val1/2)<<endl;
        }
        else{
            mini = min(mini,p.first);
        }
    }

    ll ans=0;

    while(true){
        if(pii1.empty()){
            break;
        }

        pii top1 = pii1.top();
        pii top2 = pii2.top();


        ll limit = min(top1.second,top2.second);
        ll mincost = (limit)*(min(mini,top1.first) + min(mini,top2.first));
        ans+=min<ll>(mincost,limit*(min(top1.first,top2.first)));

        pii1.pop();
        pii2.pop();

        if(limit!=top1.second){
            pii1.push(mp(top1.first,top1.second-limit));
        }

        if(limit!=top2.second){
            pii2.push(mp(top2.first,top2.second-limit));
        }
    }
    cout<<ans<<endl;
    return ans;
}




class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        return ans(basket1,basket2);
    }
};