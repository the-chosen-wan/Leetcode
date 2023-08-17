#include<iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include<chrono>
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair


int ans(vector<int> arr){
    int n = arr.size();
    int mini = arr[0];
    int pref = arr[0];

    for(int i=1;i<n;i++){
        pref+=arr[i];
        mini = min(pref,mini);
    }

    return 1-mini;
}