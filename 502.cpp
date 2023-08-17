#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(int k,int w,vector<int>& profits,vector<int>& capital){
    int n = profits.size();

    vector<pii> pairs;

    for(int i=0;i<n;i++)
        pairs.pb(mp(capital[i],profits[i]));

    sort(pairs.begin(),pairs.end());

    priority_queue<int,vector<int>> pq;

    int currind = 0;

    for(int i=0;i<k;i++){
        while(currind<n&&pairs[currind].first<=w){
            pq.push(pairs[currind].second);
            currind++;
        }

        if(!pq.empty()){
            int top = pq.top();
            w+=top;
            pq.pop();
        }
    }

    return w;
}

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        return ans(k,w,profits,capital);
    }
};

