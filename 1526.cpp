#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int mini(vector<int>& nums){
    stack<int> s;
    int n = nums.size();
    vector<int> ans(n,0);
    ans[0] = nums[0];

    for(int i=0;i<nums.size();i++){
        if(s.empty())
            s.push(i);
        else{
            int top = nums[s.top()];
            if(top>=nums[i]){
                ans[i] = ans[i-1];
                s.push(i);
                continue;
            }

            while(top<nums[i]){
                s.pop();
                if(s.empty())
                    break;
                top = nums[s.top()];
            }

            if(!s.empty()){
                ans[i]+=ans[s.top()];
                ans[i]+=(nums[i]-nums[i-1]);
            }
            else{
                ans[i] = nums[i];
            }
            s.push(i);
        }
    }
    return ans[n-1];
}

class Solution
{
public:
    int minNumberOperations(vector<int> &target)
    {
        return mini(target);
    }
};