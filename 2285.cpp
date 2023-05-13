#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define inf (int)((1e9) + 7)
#define pb push_back
#define mp make_pair

ll ans(int n,vector<vector<int>>& roads){
    vector<ll> deg(n,0);
    int m = roads.size();
    for(int i=0;i<m;i++){
        deg[roads[i][0]]++;
        deg[roads[i][1]]++;
    }

    sort(deg.begin(),deg.end());
    ll ans = 0;
    for(int i=n-1;i>=0;i--)
        ans+=((i+1)*deg[i]);
    return ans;
}

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        return ans(n,roads);
    }
};