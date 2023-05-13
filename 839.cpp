#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool check(string &s1, string &s2)
{
    int n = s1.size();
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
            c++;
        if (c > 2)
            return false;
    }
    return true;
}

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

int ans(vector<string> &str)
{
    int n = str.size();
    vector<int> parent;
    vector<int> rank;

    initialize(n, parent, rank);
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (find_parent(i, parent) == find_parent(j, parent))
                continue;
            if (check(str[i], str[j]))
            {
                union_set(i, j, parent, rank);
                ans--;
            }
        }
    }
    return ans;
}

class Solution
{
public:
    int numSimilarGroups(vector<string> &strs)
    {
        return ans(strs);
    }
};