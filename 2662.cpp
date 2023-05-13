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

int ans(vector<int>& start,vector<int>& target,vector<vector<int>>& special){
    map<pii,int> setta;
    int cnt = 0;

    auto abspair = [](pii& a,pii& b)->int{
        return abs(a.first-b.first)+abs(a.second-b.second);
    };

    setta[mp(start[0],start[1])] = cnt++;

    int n = special.size();

    for(int i=0;i<n;i++){
        pii p1 = mp(special[i][0],special[i][1]);
        pii p2 = mp(special[i][2],special[i][3]);

        if(setta.find(p1)==setta.end()){
            setta[p1]=cnt++;
        }

        if(setta.find(p2)==setta.end()){
            setta[p2]=cnt++;
        }
    }

    pii targ = mp(target[0],target[1]);
    pii src = mp(start[0],start[1]);

    if(setta.find(targ)==setta.end())
        setta[targ]=cnt++;
    
    vector<vector<pii>> adj(cnt);
    
    int targind = setta[targ];

    adj[0].pb(mp(abspair(src,targ),cnt-1));

    for(int i=0;i<n;i++){
        pii tup1 = mp(special[i][0],special[i][1]);
        pii tup2 = mp(special[i][2],special[i][3]);

        int i1 = setta[tup1];
        int i2 = setta[tup2];

        adj[0].pb(mp(abspair(src,tup1),i1));
        adj[0].pb(mp(abspair(src,tup2),i2));

        adj[i1].pb(mp(abspair(targ,tup1),targind));
        adj[i2].pb(mp(abspair(targ,tup2),targind));

        adj[i1].pb(mp(min(abspair(tup1,tup2),special[i][4]),i2));
    }

    for(int i=0;i<n;i++){
        pii tup1 = mp(special[i][0],special[i][1]);
        pii tup2 = mp(special[i][2],special[i][3]);
        int i1 = setta[tup1];
        int i2 = setta[tup2];

        for(int j=i+1;j<n;j++){
            pii tup3 = mp(special[j][0],special[j][1]);
            pii tup4 = mp(special[j][2],special[j][3]);
            int j1 = setta[tup3];
            int j2 = setta[tup4];

            adj[i1].pb(mp(abspair(tup1,tup3),j1));
            adj[j1].pb(mp(abspair(tup1,tup3),i1));

            adj[i1].pb(mp(abspair(tup1,tup4),j2));
            adj[j2].pb(mp(abspair(tup1,tup4),i1));

            adj[i2].pb(mp(abspair(tup2,tup3),j1));
            adj[j1].pb(mp(abspair(tup2,tup3),i2));

            adj[i2].pb(mp(abspair(tup2,tup4),j2));
            adj[j2].pb(mp(abspair(tup2,tup4),i2));
        }
    }

    vector<int> mindist(cnt,inf);
    mindist[0] = 0;
    set<pii> minna;
    minna.insert(mp(mindist[0],0));

    while(!minna.empty()){
        pii minpoint = *minna.begin();
        minna.erase(minpoint);
        mindist[minpoint.second] = minpoint.first;

        for(pii& node:adj[minpoint.second]){
            
            if(mindist[node.second]>mindist[minpoint.second]+node.first){
                minna.erase(mp(mindist[node.second],node.second));
                mindist[node.second] = mindist[minpoint.second]+node.first;
                minna.insert(mp(mindist[node.second],node.second));
            }
        }
    }

    return mindist[targind];
}

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        return ans(start,target,specialRoads);
    }
};