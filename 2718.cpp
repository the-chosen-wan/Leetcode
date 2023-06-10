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

ll ans(int n,vector<vector<int>>& queries){

    int coltypes=0;
    int rowtypes=0;
    unordered_set<int> setRows;
    unordered_set<int> setCols;

    int ind=queries.size();
    ll ans=0;

    for(int i=ind-1;i>=0;i--){
        if(queries[i][0]==0&&setRows.find(queries[i][1])==setRows.end()){
            rowtypes+=1;
            ans+=(n-coltypes)*queries[i][2];
            setRows.insert(queries[i][1]);
        }

        else if(queries[i][0]==1&&setCols.find(queries[i][1])==setCols.end()){
            coltypes+=1;
            ans+=(n-rowtypes)*queries[i][2];
            setCols.insert(queries[i][1]);
        }
    }

    return ans;
}

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        return ans(n,queries);
    }
};