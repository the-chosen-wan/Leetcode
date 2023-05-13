#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

void ans(int n, int k,int pos,int worker,int sum,int mask, int localmax,int& globalmin,vector<int>& nums){
    if(pos==n&&worker==k){
        globalmin = min(globalmin,localmax);
        return;
    }

    if(pos==n){
        localmax = max(sum,localmax);
        if(localmax>globalmin)
            return;
        ans(n,k,pos,worker+1,0,mask,localmax,globalmin,nums);
        return;
    }

    if((mask&(1<<n))!=1){
        if(worker!=k-1){
            ans(n,k,pos+1,worker,sum+nums[pos],mask|(1<<n),localmax,globalmin,nums);
            ans(n,k,pos+1,worker,sum,mask,localmax,globalmin,nums);
        }

        else{
            ans(n,k,pos+1,worker,sum+nums[pos],mask|(1<<n),localmax,globalmin,nums);
        }
    }
    return;
}

class Solution
{
public:
    int distributeCookies(vector<int> &cookies, int k)
    {
        int globalmin = inf;
        int localmax = -inf;
        int n = cookies.size();
        ans(n,k,0,0,0,0,localmax,globalmin,cookies);
        return globalmin;    
    }
};