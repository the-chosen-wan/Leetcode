#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define inf (ll)((1e9) + 7)
#define pb push_back
#define mp make_pair

string ans(vector<int>& nums){
    int n = nums.size();
    sort(nums.begin(),nums.end(),greater<int>());

    vector<int> cnt(3,0);

    for(int i=0;i<n;i++){
        cnt[nums[i]%3]++;
    }

    auto check = [&](int mod)->bool{
        if(cnt[mod]>0)
            return true;

        if(mod==1){
            if(cnt[2]>2)
                return true;
        }

        if(mod==2){
            if(cnt[1]>2)
                return true;
        }
        
        else{
            if(cnt[1]>=3||cnt[2]>=3)
                return true;
            
            if(cnt[1]>=1&&cnt[2]>=1)
                return true;
        }
        
        return false;
    };

    string ans = "";

    for(int i=0;i<n;i++){
        cnt[nums[i]%3]--;

        if(check((3-nums[i]%3)%3)){
            ans+=(nums[i]+'0');
        }
        else{
            cnt[nums[i]%3]++;
        }
    }

    return ans;
}

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        return ans(digits);
    }
};