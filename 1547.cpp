#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int mini(int n,vector<int>& cuts){
    vector<int> pq;
    sort(cuts.begin(),cuts.end());
    int prev = 0;
    for(int i=0;i<cuts.size();i++){
        pq.pb(cuts[i]-prev);
        prev = cuts[i];
    }

    pq.pb(n-prev);

    int cost = 0;
    while(pq.size()>1){
        int mini = inf;
        int pos = -1;
        for(int i=0;i<pq.size()-1;i++){
            if(pq[i]+pq[i+1]<mini){
                mini = pq[i]+pq[i+1];
                pos=i;
            }
            auto it = pq.begin()+i;
            pq.erase(it);
            pq.erase(it);
            pq.insert(it,mini);
            cost+=mini;
        }
    }
    return cost;
}

class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        return mini(n,cuts);
    }
};