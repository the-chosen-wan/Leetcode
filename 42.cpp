#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int>& nums){
    int n = nums.size();
    stack<pii> sp;
    int maxa = 0;

    vector<int> prefsum(n,0);
    prefsum[0] = nums[0];

    for(int i=1;i<n;i++){
        prefsum[i] = prefsum[i-1]+nums[i];
    }

    auto range = [&](int l,int r)->int{
        if(l>r)
            return 0;

        if(l==0)
            return prefsum[r];
        
        return prefsum[r]-prefsum[l-1];
    };

    stack<pii> sp;
    int ans = 0;

    for(int i=0;i<n;i++){
        if(sp.empty()){
            sp.push(mp(i,nums[i]));
        }

        else{
            pii top = sp.top();
            pii backup = top;
            while(top.second<nums[i]){
                sp.pop();

                if(sp.empty())
                    break;
                
                top = sp.top();
            }

            sp.push(mp(i,nums[i]));
            
        }
    }
}

class Solution
{
public:
    int trap(vector<int> &height)
    {
        return ans(height);
    }
};