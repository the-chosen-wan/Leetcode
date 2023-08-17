#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

void initialize(int n,vector<int>& parent,vector<int>& size){
    parent.resize(n);
    size.resize(n);

    for(int i=0;i<n;i++){
        parent[i]=i;
        size[i]=1;
    }
    return;
}

int find_sets(int v,vector<int>& parent){
    if(v==parent[v])
        return v;
    return parent[v]=find_sets(parent[v],parent);
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

int ans(int n,vector<vector<int>>& edges){
    int m = edges.size();
    if(m<n-1)
        return -1;
    
    int cnt=n;
    vector<int> parent,size;
    initialize(n,parent,size);

    for(vector<int>& e:edges){
        if(find_sets(e[0],parent)!=find_sets(e[1],parent)){
            cnt--;
            union_sets(e[0],e[1],parent,size);
        }

    }
    return --cnt;
}

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        return ans(n,connections);
    }
};