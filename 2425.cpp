#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e7;
#define pb push_back
#define pf push_front
#define mp make_pair

int ans(vector<int>& num1,vector<int>& num2){
    int n1 = num1.size();
    int n2 = num2.size();

    int x = 0;

    if(n1&1){
        for(int k:num2)
            x^=k;
    }

    if(n2&1){
        for(int k:num1)
            x^=k;
    }
    return x;
}

class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        return ans(nums1,nums2);
    }
};