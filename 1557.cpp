#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

vector<int> ans(int n,vector<vector<int>>& edges){
    vector<int> indegree(n,0);

    int m = edges.size();

    for(int i=0;i<m;i++)
        indegree[edges[i][1]]++;
    
    vector<int> ans;

    for(int i=0;i<n;i++){
        if(indegree[i]==0)
            ans.pb(i);
    }

    return ans;
}

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        return ans(n,edges);
    }
};