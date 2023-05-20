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

int ans(int n,vector<int>& costs){
    vector<int> mini(n+1,0);
    int ans = 0;

    auto dfs = [&](int pos,auto&& dfs)->void{
        if(2*pos>n){
            mini[pos] = costs[pos-1];
            return;
        }

        dfs(2*pos,dfs);
        dfs(2*pos+1,dfs);

        mini[pos] = costs[pos-1]+max(mini[2*pos],mini[2*pos+1]);

        ans+=max(mini[2*pos+1],mini[2*pos]) - min(mini[2*pos+1],mini[2*pos]);

        return;
    };

    dfs(1,dfs);
    return ans;
}

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        return ans(n,cost);
    }
};