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

int ans(vector<vector<int>>& grid) {
    int n  =grid.size();
    int m = grid[0].size();

    if(grid[0][1]>1&&grid[1][0]>1)    
        return -1;

    vector<vector<int>> adj(n*m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int val = i*m + j;
            int val1 = (i-1)*m+j;
            int val2 = (i+1)*m+j;
            int val3 = i*m+j-1;
            int val4 = i*m+j+1;

            if(i>0)
                adj[val].pb(val1);
            if(i<n-1)
                adj[val].pb(val2);
            if(j>0)
                adj[val].pb(val3);
            if(j<m-1)
                adj[val].pb(val4);
        }
    }

    auto getind = [&](int x)->pii{
        int first = x/m;
        int second = x - first*m;
        return mp(first,second);
    };

    vector<int> mindist(n*m,inf);
    mindist[0] = 0;
    set<pii> minni;
    minni.insert(mp(0,0));

    while(!minni.empty()){
        auto frontptr = minni.begin();
        pii front = *frontptr;
        minni.erase(frontptr);

        for(int j:adj[front.second]){
            pii indices = getind(j);

            int cost = 0;
            if(front.first+1>=grid[indices.first][indices.second])
                cost = front.first+1;
            else{
                if((grid[indices.first][indices.second]-front.first)%2==1)
                    cost = grid[indices.first][indices.second];
                else
                    cost = grid[indices.first][indices.second] + 1;
            }

            if(cost<mindist[j]){
                minni.erase(mp(mindist[j],j));
                mindist[j]=cost;
                minni.insert(mp(mindist[j],j));
            }
        }
    }
    
    return mindist[n*m-1];
}

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        return ans(grid);
    }
};