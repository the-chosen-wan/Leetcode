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

vector<int> ans(int n, vector<vector<int>>& logs, int x, vector<int>& queries){
    vector<pii> logga;
    int l = logs.size();
    int q = queries.size();
    
    vector<pii> newqueries;
    
    for(int i=0;i<q;i++){
        newqueries.pb(mp(queries[i],i));
    }
    
    sort(newqueries.begin(),newqueries.end());

    for(int i=0;i<l;i++){
        logga.pb(mp(logs[i][1],logs[i][0]));
    }

    sort(logga.begin(),logga.end());

    vector<int> ans(q,0);

    int low = 0;
    int high = 0;
    int zerocnt = n;
    vector<int> currcnt(n,0);

    for(int i=0;i<q;i++){
        int lower = newqueries[i].first-x;
        int higher = newqueries[i].first;

        while(high<l&&logga[high].first<=higher) {
            if(currcnt[logga[high].second-1]==0)
                zerocnt--;
            currcnt[logga[high].second-1]++;
            high++;
        }

        while(low<l&&logga[low].first<lower) {
            currcnt[logga[low].second-1]--;

            if(currcnt[logga[low].second-1]==0)
                zerocnt++;
            low++;
        }

        ans[newqueries[i].second]=zerocnt;
    }

    return ans;
}

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        return ans(n,logs,x,queries);
    }
};