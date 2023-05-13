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

int ans(vector<int>& reward1,vector<int>& reward2,int k){

    int n = reward1.size();

    vector<int> arr3(n,0);

    for(int i=0;i<n;i++){
        arr3[i] = reward1[i] - reward2[i];
    }

    sort(arr3.begin(),arr3.end(),greater<int>());

    int sum = 0;

    for(int i=0;i<n;i++)
        sum+=reward2[i];
    
    for(int i=0;i<k;i++)
        sum+=arr3[i];
    
    return sum;
}

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        return ans(reward1,reward2,k);
    }
};