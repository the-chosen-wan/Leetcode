#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tup = tuple<int,int,char,int>;
#include<chrono>
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

vector<int> ans(vector<int>& pos,vector<int>& health,string dir) {
    int n = pos.size();
    vector<tuple<int,int,char,int>> posh;

    for(int i=0;i<n;i++)
        posh.pb(make_tuple(pos[i],health[i],dir[i],i));

    sort(posh.begin(),posh.end());
    stack<tuple<int,int,char,int>> stackup;

    vector<pii> ans;

    for(int i=0;i<n;i++){
        if(stackup.empty())
            stackup.push(posh[i]);
        
        else{
            tup top = stackup.top();

            while(get<2>(top)=='L'){
                ans.pb(mp(get<3>(top),get<1>(top)));
                stackup.pop();

                if(stackup.empty())
                    break;
                top=stackup.top();
            }

            tup curr = posh[i];

            if(get<2>(curr)=='R') {
                stackup.push(curr);
            }
            else{
                if(stackup.empty()||get<2>(stackup.top())=='L'){
                    stackup.push(curr);
                }
                else{
                    tup top = stackup.top();
                    int cnt = get<1>(curr);
                    while(!stackup.empty()&&get<2>(stackup.top())=='R'){
                        if(get<1>(top)>cnt) {
                            stackup.pop();
                            stackup.push(make_tuple(get<0>(top),get<1>(top)-1,get<2>(top),get<3>(top)));
                            cnt=-1;
                            break;
                        }

                        else if(get<1>(top)<cnt) {
                            stackup.pop();
                            cnt--;
                        }

                        else {
                            stackup.pop();
                            cnt = -1;
                            break;
                        }

                        if(!stackup.empty())
                            top = stackup.top();
                    }

                    if(cnt!=-1){
                        stackup.push(make_tuple(get<0>(curr),cnt,get<2>(curr),get<3>(curr)));
                    }
                }
            }
        }
    }

    while(!stackup.empty()){
        ans.pb(mp(get<3>(stackup.top()),get<1>(stackup.top())));
        stackup.pop();
    }

    sort(ans.begin(),ans.end());
    vector<int> temp;

    int a = ans.size();

    for(int i=0;i<a;i++)
        temp.pb(ans[i].second);
    return temp;
}

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        return ans(positions,healths,directions);
    }
};