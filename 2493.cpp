#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
const int N = (1e5)+1;
#define pb push_back
#define pf push_front
#define mp make_pair

int ans(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<vector<int>> components;

    int m = edges.size();

    for(int i=0;i<m;i++){
        adj[edges[i][0]-1].pb(edges[i][1]-1);
        adj[edges[i][1]-1].pb(edges[i][0]-1);
    }

    vector<int> color(n,-1);
    vector<int> maxlevel(n,1);

    auto bfs = [&](int src)->int{
        color[src] = 0;
        queue<int> q;
        q.push(src);
        components.pb({src});
        int len = components.size();

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(int v:adj[front]){
                if(color[v]==-1){
                    color[v]=1-color[front];q.push(v);
                    components[len-1].pb(v);
                }
                else{
                    if(color[v]!=1-color[front])
                        return -1;
                }
            }
        }
        return 1;
    };

    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(bfs(i)==-1)
                return -1;
        }
    }

    auto bfscnt = [&](int src)->int{
        color[src] = 1;
        int ret=-1;

        queue<int> q;
        q.push(src);
        maxlevel[src]=1;

        while(!q.empty()){
            int front = q.front();
            ret = max(ret,maxlevel[front]);
            q.pop();

            bool one  = false;
            for(int v:adj[front]) {
                if(color[v]==-1){
                    color[v]=1;
                    q.push(v);
                    maxlevel[v]=maxlevel[front]+1;
                }
            }
        }
        return ret;
    };

    int len = components.size();
    int total = 0;

    for(int i=0;i<len;i++){
        int maxa=-1;
        for(int j:components[i]){
            color.assign(n,-1);
            maxa = max(maxa,bfscnt(j));
        }
        total+=maxa;
    }
    return total;
}

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        return ans(n,edges);
    }
};