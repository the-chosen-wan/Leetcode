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

int ans(vector<int>& nums) {
    int n = nums.size();

    int ans = 0;
    unordered_map<int,int> mappa;
    set<int> numbers;

    for(int i=0;i<n;i++){
        int num = nums[i];

        auto upperptr = numbers.upper_bound(num);

        if(upperptr!=numbers.end()){
            int big = *upperptr;

            int ind = mappa[big];

            
        }
    }
}