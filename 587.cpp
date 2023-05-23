#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

bool check(pii x1,pii x2,pii x3){
    if(x3.first==x2.first)
        return true;
    
    return (x2.second-x1.second)*(x3.first-x2.first) < (x3.second-x2.second)*(x2.first-x1.first);
}



void remove(std::vector<vector<int>> &v)
{
    std::vector<vector<int>>::iterator itr = v.begin();
    std::set<vector<int>> s;
 
    for (auto curr = v.begin(); curr != v.end(); ++curr)
    {
        if (s.insert(*curr).second) {
            *itr++ = *curr;
        }
    }
 
    v.erase(itr, v.end());
}

vector<vector<int>> ans(vector<vector<int>>& trees){
    int n = trees.size();
    vector<pii> points;
    vector<vector<int>> ans;
    int minx = inf;
    int maxx =-inf;

    for(int i=0;i<n;i++){
        points.pb(mp(trees[i][0],trees[i][1]));
        minx = min(minx,trees[i][0]);
        maxx = max(maxx,trees[i][0]);
    }

    for(int i=0;i<n;i++){
        if(trees[i][0]==minx||trees[i][0]==maxx)
            ans.pb(trees[i]);
    }
    
    sort(points.begin(),points.end());

    stack<pii> conv;

    for(int i=0;i<n;i++){
        if(conv.size()<=1){
            conv.push(points[i]);
            continue;
        }

        pii top = conv.top();
        conv.pop();
        pii second = conv.top();
        conv.push(top);

        while(conv.size()>1&&check(second,top,points[i])){
            conv.pop();
            
            if(conv.size()==1)
                break;
            
            top = conv.top();
            conv.pop();
            second = conv.top();
            conv.push(top);
        }

        conv.push(points[i]);
    }

    while(!conv.empty()){
        pii top = conv.top();
        ans.pb({top.first,top.second});
        conv.pop();
    }

    points.clear();

    for(int i=0;i<n;i++){
        points.pb(mp(trees[i][0],-trees[i][1]));
    }

    sort(points.begin(),points.end());

    for(int i=0;i<n;i++){
        if(conv.size()<=1){
            conv.push(points[i]);
            continue;
        }

        pii top = conv.top();
        conv.pop();
        pii second = conv.top();
        conv.push(top);

        while(conv.size()>1&&check(second,top,points[i])){
            conv.pop();
            
            if(conv.size()==1)
                break;
            
            top = conv.top();
            conv.pop();
            second = conv.top();
            conv.push(top);
        }

        conv.push(points[i]);
    }

    while(!conv.empty()){
        pii top = conv.top();
        ans.pb({top.first,-top.second});
        conv.pop();
    }
    remove(ans);
    return ans;
}

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        return ans(trees);
    }
};