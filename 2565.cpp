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

int ans(vector<vector<int>>& edges,vector<vector<int>>& guesses,int k){
    int n = edges.size()+1;

    set<pii> guessed;
    int g = guesses.size();


    for(int i=0;i<g;i++){
        guessed.insert(mp(guesses[i][0],guesses[i][1]));
    }

    vector<vector<int>> adj(n);
    int ans=0;

    for(int i=0;i<n-1;i++){
        adj[edges[i][0]].pb(edges[i][1]);
        adj[edges[i][1]].pb(edges[i][0]);
    }

    int counter = 0;

    auto normalDfs = [&](int src,int par,auto&& normalDfs)->void{
        if(src!=par){
            if(guessed.find(mp(par,src))!=guessed.end())
                counter++;
        }

        for(int node:adj[src]){
            if(node!=par){
                normalDfs(node,src,normalDfs);
            }
        }

        return;
    };

    normalDfs(0,0,normalDfs);
    if(counter>=k)
        ans++;

    auto actualDfs = [&](int src,int par,auto&& actualDfs)->void{
        bool firstFound = false;
        bool secondFound = false;
        if(src!=par){
            if(guessed.find(mp(par,src))!=guessed.end())
                {counter--;firstFound=true;}
            
            if(guessed.find(mp(src,par))!=guessed.end())
                {counter++;secondFound=true;}

            if(counter>=k)
                ans++;
        }

        for(int node:adj[src]){
            if(node!=par){
                actualDfs(node,src,actualDfs);
            }
        }

        if(src!=par){
            if(firstFound)
                counter++;

            if(secondFound)
                counter--;
        }

        return;
    };
    
    actualDfs(0,0,actualDfs);

    return ans;
}


class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        return ans(edges,guesses,k);
    }
};