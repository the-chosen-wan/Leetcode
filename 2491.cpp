#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

ll ans(vector<int>& skill){
    int n = skill.size();

    sort(skill.begin(),skill.end());

    ll sum = accumulate(skill.begin(),skill.end(),0LL)/(n/2);
    int low = 0;
    int high = n-1;

    ll ans = 0;

    for(int i=0;i<n/2;i++){
        if(skill[low]+skill[high]!=sum)
            return -1;
        ans+=(skill[low]*skill[high]);
        low++;
        high--;
    }

    return ans;
}

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        return ans(skill);
    }
};