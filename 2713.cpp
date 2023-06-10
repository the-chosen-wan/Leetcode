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


int ans(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> adj(n*m);

    for(int i=0;i<n;i++){
        vector<pii> pairs;
        for(int j=0;j<m;j++){
            pairs.pb(mp(mat[i][j],i*m+j));
        }

        sort(pairs.begin(),pairs.end());

        for(int j=0;j<m-1;j++){
            if(pairs[j].first<pairs[j+1].first)
                adj[pairs[j].second].pb(pairs[j+1].second);
        }
    }

    for(int j=0;j<m;j++){
        vector<pii> pairs;

        for(int i=0;i<n;i++){
            pairs.pb(mp(mat[i][j],i*m+j));
        }

        sort(pairs.begin(),pairs.end());

        for(int i=0;i<n-1;i++){
        if(pairs[i].first<pairs[i+1].first)
            adj[pairs[j].second].pb(pairs[j+1].second);
        }
    }


    vector<int> dp(n*m,-1);

    int cnt=0;
    auto dfs = [&](int src,auto&& dfs)->void{
    };
}