#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

void make_set(int n, vector<int> &parent)
{
    parent.resize(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    return;
}

int find_parent(int i, vector<int> &parent)
{
    if (parent[i] == i)
        return i;
    return parent[i] = find_parent(parent[i], parent);
}

vector<int> ans(vector<vector<int>> &paint)
{
    int m = paint.size();
    int n = -inf;
    for (int i = 0; i < m; i++)
        n = max(n, paint[i][1]);

    vector<int> parent;
    make_set(n + 2, parent);
    vector<int> ans;

    for (int i = 0; i < m; i++)
    {
        int c = 0;
        int l = paint[i][0];
        int r = paint[i][1];

        for (int j = find_parent(l, parent); j < r; j = find_parent(j, parent))
        {
            c++;
            parent[j] = j + 1;
        }
        ans.pb(c);
    }
    return ans;
}

class Solution
{
public:
    vector<int> amountPainted(vector<vector<int>> &paint)
    {
        return ans(paint);
    }
};