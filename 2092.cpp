#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

void initialize(int n, vector<int> &parent, vector<int> &size, vector<int> &secret)
{
    parent.resize(n);
    size.resize(n);
    secret.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        size[i] = 1;
        secret[i] = 0;
    }
    return;
}

int find_sets(int v, vector<int> &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_sets(parent[v], parent);
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &size, vector<int> &secret)
{
    a = find_sets(a, parent);
    b = find_sets(b, parent);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        secret[a] |= secret[b];
    }
    return;
}

bool comp(vector<int> &s1, vector<int> &s2)
{
    if (s1[2] != s2[2])
        return s1[2] < s2[2];
    else if (s1[1] != s2[1])
        return s1[1] < s2[1];
    else
        return s1[0] < s2[0];
}

vector<int> ans(int n, vector<vector<int>> &meeting, int first)
{
    vector<int> ans;
    sort(meeting.begin(), meeting.end());
    vector<int> parent, size, secret;
    initialize(n, parent, size, secret);
    secret[0] = 1;
    secret[first] = 1;
    int m = meeting.size();
    for (int i = 0; i < m; i++)
    {
        if (secret[find_sets(meeting[i][0], parent)] == 0 && secret[find_sets(meeting[i][1],parent)] == 0)
            continue;
        union_sets(meeting[i][0], meeting[i][1], parent, size, secret);
    }

    for (int i = 0; i < n; i++)
    {
        if (secret[find_sets(i, parent)])
            ans.pb(i);
    }
    return ans;
}

class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        return ans(n, meetings, firstPerson);
    }
};