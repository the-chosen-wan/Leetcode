#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
const int N = (1e5)+1;
#define pb push_back
#define pf push_front
#define mp make_pair

void initialize(int n, vector<int> &parent, vector<int> &size)
{
    parent.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
    return;
}

int find_sets(int v, vector<int> &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_sets(parent[v], parent);
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &size)
{
    a = find_sets(a, parent);
    b = find_sets(b, parent);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

vector<int> ans(vector<vector<int>>& grid,vector<int>& queries){
    int n = grid.size();
    int m = grid[0].size();

    int q = queries.size();

    vector<pii> sortedq;

    for(int i=0;i<q;i++)
        sortedq.pb(mp(queries[i],i));
    sort(sortedq.begin(),sortedq.end());

    vector<int> parent,size;
    initialize(m*n,parent,size);

    vector<pii> edges;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            edges.pb(mp(grid[i][j],i*m+j));
    }

    sort(edges.begin(),edges.end());

    vector<int> ans(q);
    int cnt = 0;
    const int N = m*n;
    vector<bool> seen(N,false);

    for(int i=0;i<q;i++){
        while(cnt<N&&edges[cnt].first<sortedq[i].first){
            int index = edges[cnt].second;
            int xind = index/m;
            int yind = index - (m*xind);
            seen[index] = true;

            int val1 = m*(xind-1)+yind;
            int val2 = m*(xind+1)+yind;
            int val3 = m*xind + yind -1;
            int val4 = m*xind + yind + 1;

            if(xind>0&&seen[val1])
                union_sets(index,val1,parent,size);
            if(xind<n-1&&seen[val2])
                union_sets(index,val2,parent,size);
            if(yind>0&&seen[val3])
                union_sets(index,val3,parent,size);
            if(yind<m-1&&seen[val4])
                union_sets(index,val4,parent,size);
            cnt++;
        }

        if(grid[0][0]>=sortedq[i].first){
            ans[sortedq[i].second] = 0;
        }

        else{
            ans[sortedq[i].second] = size[find_sets(0,parent)];
        }
    }
    return ans;
}

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        return ans(grid,queries);
    }
};