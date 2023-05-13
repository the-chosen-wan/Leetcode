#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int ans(int n,vector<vector<int>>& m){
    vector<pii> meetings;
    int ms = m.size();

    for(int i=0;i<ms;i++){
        meetings.pb(mp(m[i][0],m[i][1]));
    }

    sort(meetings.begin(),meetings.end());

    vector<int> cnt(n,0);
    priority_queue<pii,vector<pii>,greater<pii>> canuse;
    priority_queue<int,vector<int>,greater<int>> index;

    for(int i=0;i<n;i++)
        index.push(i);

    for(int i=0;i<ms;i++){
        ll starttime=meetings[i].first;
        ll endtime=meetings[i].second;

        while(!canuse.empty()&&canuse.top().first<=starttime){
            int ind = canuse.top().second;
            canuse.pop();
            index.push(ind);
        }

        if(index.empty()){
            starttime=canuse.top().first;
            endtime=meetings[i].second-meetings[i].first+starttime;
            index.push(canuse.top().second);
            canuse.pop();
        }

        int ind=index.top();
        index.pop();
        cnt[ind]++;
        canuse.push(mp(endtime,ind));
    }

    int mini = *max_element(cnt.begin(),cnt.end());
    int a=-1;
    for(int i=0;i<n;i++){
        if(cnt[i]==mini){
            a=i;
            break;
        }
    }

    return a;
}

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        return ans(n,meetings);
    }
};

int main(){
    return 0;
}