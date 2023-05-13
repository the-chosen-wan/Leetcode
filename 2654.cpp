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

int ans(vector<int>& nums){
    int n = nums.size();
    int a = nums[0];
    int ones = nums[0]==1;

    for(int i=1;i<n;i++){
        a = __gcd(a,nums[i]);

        if(nums[i]==1)
            ones++;
    }

    if(a!=1&&ones!=n)
        return -1;

    if(ones)
        return n-ones;

    int minarray = inf;

    for(int i=0;i<n;i++){
        int gcd = nums[i];

        for(int j=i+1;j<n;j++){
            gcd = __gcd(gcd,nums[j]);

            if(gcd==1){
                minarray = min(minarray,j-i+1);
                break;
            }
        }
    }
    minarray--;
    return n-1+minarray;
}

class Solution {
public:
    int minOperations(vector<int>& nums) {
        return ans(nums);
    }
};