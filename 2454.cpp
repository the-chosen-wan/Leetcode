#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

vector<int> ans(vector<int>& nums){
    int n = nums.size();
    vector<int> next(n,-1);

    stack<pii> st;

    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            st.push(mp(nums[i],i));
        }

        else{
            pii top = st.top();

            while(!st.empty()&&top.first<=nums[i]){
                st.pop();
                if(!st.empty())
                    top = st.top();
            }

            if(st.empty())
                next[i] = -1;
            
            else
                next[i] = top.second;
            st.push(mp(nums[i],i));
        }
    }

    vector<int> ans(n,-1);

    set<int> setta;
    vector<vector<int>> nextarray(n);

    for(int i=0;i<n;i++){
        if(next[i]!=-1)
            nextarray[next[i]].pb(i);
    }

    for(int i=n-1;i>=1;i--){

        while(!setta.empty()){
            auto ptr = setta.begin();
            int end = *ptr;
            if(end<=nums[i]){
                setta.erase(ptr);
            }
            else
                break;
        }
        setta.insert(nums[i]);

        for(int& j: nextarray[i-1]){
            auto ptr = setta.upper_bound(nums[j]);

            if(ptr==setta.end())
                continue;
            
            ans[j] = *ptr;
        }
    }
    return ans;
}

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        return ans(nums);
    }
};