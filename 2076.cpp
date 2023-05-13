#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

void initialize(int vertices, vector<int> &parent, vector<int> &rank1)
{
    parent.resize(vertices);
    rank1.resize(vertices);
    for (int i = 0; i < vertices; i++)
    {
        parent[i] = i;
        rank1[i] = 0;
    }
}
int find_parent(int v, vector<int> &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_parent(parent[v], parent);
}
void union_set(int v1, int v2, vector<int> &parent, vector<int> &rank1)
{
    v1 = find_parent(v1, parent);
    v2 = find_parent(v2, parent);
    if (rank1[v1] < rank1[v2])
        parent[v1] = v2;
    else if (rank1[v1] > rank1[v2])
        parent[v2] = v1;
    else
    {
        parent[v1] = v2;
        rank1[v2]++;
    }
}

vector<bool> reqs(int n, vector<vector<int>> &rest, vector<vector<int>> reqs)
{
    vector<pii> res;
    vector<pii> req;

    for (int i = 0; i < rest.size(); i++)
        res.pb(mp(rest[i][0], rest[i][1]));
    for (int i = 0; i < reqs.size(); i++)
        req.pb(mp(reqs[i][0], reqs[i][1]));

    vector<int> parent;
    vector<int> rank;

    initialize(n, parent, rank);

    vector<bool> ans;

    for (pii r : req)
    {
        int par1 = find_parent(r.first, parent);
        int par2 = find_parent(r.second, parent);

        bool accept = true;
        for (pii restric : res)
        {
            int res1 = find_parent(restric.first, parent);
            int res2 = find_parent(restric.second, parent);

            if (((res1 == par1) && (res2 == par2)) || ((res1 == par2) && (res2 == par1)))
            {
                accept = false;
                break;
            }
        }
        ans.pb(accept);
        if (accept)
            union_set(r.first, r.second, parent, rank);
    }
    return ans;
}

class Solution
{
public:
    vector<bool> friendRequests(int n, vector<vector<int>> &restrictions, vector<vector<int>> &requests)
    {
        return reqs(n, restrictions, requests);
    }
};