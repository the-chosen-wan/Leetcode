#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair
#define mt make_tuple

void initialize(int n, vector<int> &parent)
{
    parent.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    return;
}

int find_sets(int v, vector<int> &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_sets(parent[v], parent);
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &velocity)
{
    a = find_sets(a, parent);
    b = find_sets(b, parent);
    if (a != b)
    {
        if(velocity[a]<velocity[b])
            parent[b] = a;
        else
            parent[a] = b;
    }
}

vector<double> ans(vector<vector<int>>& cars){
    int n = cars.size();
    vector<double> ans(n,-1);

    using tup = tuple<int,int>;

    vector<int> pos(n);
    vector<int> velocity(n);
    priority_queue<tup,vector<tup>> pq;

    for(int i=0;i<n;i++){
        pos[i] = cars[i][0];
        velocity[i] = cars[i][1];
        pq.push(mt(velocity[i],i));
    }

    vector<int> parent;
    initialize(n,parent);
    int highest = n-1;

    while(!pq.empty()){
        tup front = pq.top();
        int par = find_sets(get<1>(front),parent);
        int next = find_sets(par+1,parent);
        pq.pop();

        if(par!=get<1>(front)){
            if(next==n||velocity[next]>=velocity[par])
                continue;

            union_sets(par,next,parent,velocity);
        }

        else{
            if(next==n||velocity[next]>=velocity[par])
                continue;

            int pos1 = pos[par];
            int pos2 = pos[next];
            int ind = get<1>(front);

            ans[ind] = ((double)(pos2)-(double)(pos1))/((double)(velocity[next])-(double)(velocity[par]));
            union_sets(par,next,parent,velocity);
        }
    }
    return ans;
}

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        return ans(cars);
    }
};