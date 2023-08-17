#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

void initialize(int n,vector<int>& parent,vector<int>& size){
    parent.resize(n);
    size.resize(n);

    for(int i=0;i<n;i++){
        parent[i]=i;
        size[i]=1;
    }

    return ;
}

int find_sets(int n,vector<int>& parent){
    if(n==parent[n])
        return n;
    return parent[n] = find_sets(parent[n],parent);
}

void union_sets(int a,int b,vector<int>& parent,vector<int>& size){
    a = find_sets(a,parent);
    b = find_sets(b,parent);

    if(a!=b){
        if(size[a]>size[b])
            swap(a,b);
        parent[a]=b;
        size[b]+=size[a];
    }
    return;
}

ll ans(int n,vector<vector<int>>& edges){
    int m = edges.size();
    vector<int> parent,size;
    initialize(n,parent,size);

    for(int i=0;i<m;i++){
        union_sets(edges[i][0],edges[i][1],parent,size);
    }

    ll summa=0;
    ll sumsqr=0;
    for(int i=0;i<n;i++){
        if(i==parent[i]){
            summa+=size[i];
            sumsqr+=((ll)size[i]*(ll)size[i]);
        }
    }
    ll ans = ((summa*summa)-sumsqr)/2;
    return ans;
}

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        return ans(n,edges);
    }
};