#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair


class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> st;

        for(int i=0;i<n;i++){
            if(i==0)
                st.push(nums[i]);
            else{
                while(!st.empty()&&st.top()>nums[i]&&(k-st.size())<n-i){
                    st.pop();
                }

                if(st.size()<k)
                    st.push(nums[i]);
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};