#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair
#define mt make_tuple

int ans(int n,vector<vector<int>>& restrictions){
    int r = restrictions.size();

    if(r==0)
        return n-1;
        
    sort(restrictions.begin(),restrictions.end());

    for(int i=0;i<r;i++){
        cout<<restrictions[i][0]<<" "<<restrictions[i][1]<<endl;
    }

    int prevmax = inf;
    int globalmax = -inf;

    using tup = tuple<int,int,int>;

    stack<tup> st;
    st.push(mt(0,0,1));
    for(int i=0;i<r;i++){
        if(i==8)
            cout<<prevmax<<" "<<globalmax<<endl;
        if(i==0){
            prevmax = min(restrictions[0][0]-1,restrictions[0][1]);
            globalmax = (prevmax+restrictions[0][0]-1)/2;
            st.push(mt(prevmax,globalmax,restrictions[0][0]));
        }
        else{
            int diff = restrictions[i][0] - restrictions[i-1][0];
            int currmax = prevmax;
            prevmax = min(prevmax+diff,restrictions[i][1]);

            bool compatible = (currmax-diff)<=prevmax;

            if(compatible){
                globalmax = max(globalmax,((prevmax+currmax+diff)/2));
                st.push(mt(prevmax,globalmax,restrictions[i][0]));
            }
            else{
                st.pop();
                tup front = st.top();
                compatible = (get<0>(front) - (restrictions[i][0] - get<2>(front)))<=prevmax;

                while(!st.empty()&&!compatible){
                    st.pop();

                    if(st.empty())
                        break;
                    
                    front = st.top();
                    compatible = (get<0>(front) - (restrictions[i][0] - get<2>(front)))<=prevmax;
                }

                globalmax = max(get<1>(front),((prevmax+get<0>(front)+restrictions[i][0]-get<2>(front))/2));
                st.push(mt(prevmax,globalmax,restrictions[i][0]));
            }
        }
    }
    return max(globalmax,prevmax + n - restrictions[r-1][0]);
}

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        return ans(n,restrictions);
    }
};