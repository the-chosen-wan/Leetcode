#include <iostream>
#include <bits/stdc++.h>
#define inf (int)(1e9)
using namespace std;
using pii = pair<ll, int>;
using ll = long long;

void dj(vector<vector<pii>> &adj, vector<ll> &mindist, int source)
{
    mindist[source] = 0;
    set<pii> s;
    s.insert(make_pair(0, source));
    while (!s.empty())
    {
        pii q = *s.begin();
        s.erase(*s.begin());
        for (pii temp : adj[q.second])
        {
            if ((mindist[q.second] + temp.first) < mindist[temp.second])
            {
                s.erase(make_pair(mindist[temp.second], temp.second));
                mindist[temp.second] = mindist[q.second] + temp.first;
                s.insert(make_pair(mindist[temp.second], temp.second));
            }
        }
    }
}

ll get_max_weight(int n, vector<vector<int>> &edges, int src1, int src2, int dest){
    vector<vector<pii>> forward(n);
    vector<vector<pii>> backward(n);

    for(int i=0;i<edges.size();i++){
        int from = edges[i][0];
        int to = edges[i][1];
        int weight = edges[i][2];

        forward[from].push_back(make_pair(weight,to));
        backward[to].push_back(make_pair(weight,from));
    }

    vector<ll> mindist_src1_forward;
    mindist_src1_forward.assign(n,inf);

    vector<ll> mindist_src2_forward;
    mindist_src2_forward.assign(n,inf);

    vector<ll> mindist_dest_backward;
    mindist_dest_backward.assign(n,inf);

    dj(forward,mindist_src1_forward,src1);
    dj(forward,mindist_src2_forward,src2);
    dj(backward,mindist_dest_backward,dest);

    ll mini = inf;
    for(int i=0;i<n;i++){
        mini = min<ll>(mindist_src1_forward[i]+mindist_src2_forward[i]+mindist_dest_backward[i],mini);
    }

    if(mini >= inf)
        return -1;
    return mini;
}

class Solution
{
public:
    long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest)
    {
        return get_max_weight(n,edges,src1,src2,dest);
    }
};
