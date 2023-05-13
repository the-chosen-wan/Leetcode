#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int wotor(vector<int>& nums){
    int n = nums.size();
    stack<pii> sp;
    int maxa = 0;

    for(int i=0;i<n;i++){
        if(sp.empty())
            sp.push(mp(nums[i],i));
        else{
            pii top = sp.top();
            if(top.first>=nums[i])
                {maxa+=(top.first-nums[i])*(i-top.second);continue;}
            while(top.first<nums[i]){
                sp.pop();
                if(sp.empty())
                    break;
                top = sp.top();
            }

            if(!sp.empty())
                maxa+=(top.first-nums[i])*(i-top.second);
            sp.push(mp(nums[i],i));
        }
    }
    return maxa;
}

class Solution
{
public:
    int trap(vector<int> &height)
    {
        return wotor(height);
    }
};