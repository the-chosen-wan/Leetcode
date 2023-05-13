#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int ans(vector<vector<int>>& nums,int k){
    int n = nums.size();
    int m = nums[0].size();
    int sum = 0;
    vector<vector<int>> diff(n,vector<int>(m,0));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> startpos(n,1);

    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++)
            diff[i][j+1]=nums[i][j+1]-nums[i][j];
    }

    for(int i=0;i<n;i++)
        sum+=nums[i][0];
    if(k==1)
        return sum;
    
    for(int i=0;i<n;i++)
        pq.push(mp(diff[i][1],i));


    for(int i=2;i<=k;i++){
        pii top = pq.top();
        sum+=top.first;
        int ind = top.second;
        pq.pop();
        if(startpos[ind]==m)
            continue;
        startpos[ind]++;
        pq.push(mp(diff[ind][startpos[ind]],ind));
    }
    return sum;
}

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        return ans(mat,k);
    }
};