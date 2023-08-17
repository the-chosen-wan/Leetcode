#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define MAXN 1000000
#define bit 21
#define pb push_back
#define pf push_front
#define mp make_pair
const int N = 26;

vector<string> ans(string s){
    int n = s.size();

    vector<int> first(N,-1);
    vector<int> last(N,-1);

    for(int i=0;i<n;i++){
        if(first[s[i]-'a']==-1){
            first[s[i]-'a'] = i;
        }

        last[s[i]-'a']=i;
    }

    vector<pii> pairs;

    using tup = tuple<int,int,int>;
    using mt = make_tuple;

    priority_queue<tup,vector<tup>,greater<tup>> pq;

    for(int i=0;i<N;i++){
        if(first[i]!=-1){
            pairs.pb(mp(first[i],last[i]));
        }
    }

    sort(pairs.begin(),pairs.end());
    int ind = 0;
    vector<string> ans;
    int p = pairs.size();

    for(int i=0;i<p;i++){
        pq.push(mt(last[i],i,first[i]));
    }

    while(ind<p){
        tup top = pq.top();

        if(get<1>(top)<ind){
            pq.pop();
            continue;
        }

        ans.pb(s.substr(get<2>(top),get<0>(top)-get<2>(top)+1));

        while(ind<p&&pairs[ind].first<=get<0>(top))
            ind++;
    }

    return ans;
}

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        return ans(s);
    }
};
