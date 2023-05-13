#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
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

vector<vector<int>> ans(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int k = n * m;
    vector<int> parent, size;

    initialize(k, parent, size);
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> prevseen;
        for (int j = 0; j < m; j++)
        {
            int val = i * m + j;
            if (prevseen.find(grid[i][j]) == prevseen.end())
            {
                prevseen[grid[i][j]] = val;
                continue;
            }
            union_sets(val, prevseen[grid[i][j]], parent, size);
        }
    }

    for (int j = 0; j < m; j++)
    {
        unordered_map<int, int> prevseen;
        for (int i = 0; i < n; i++)
        {
            int val = i * m + j;
            if (prevseen.find(grid[i][j]) == prevseen.end())
            {
                prevseen[grid[i][j]] = val;
                continue;
            }
            union_sets(val, prevseen[grid[i][j]], parent, size);
        }
    }

    unordered_map<int, int> seen;
    int c = -1;
    vector<vector<int>> pargrid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val = i * m + j;
            int s = find_sets(val, parent);
            if (seen.find(s) == seen.end())
            {
                c++;
                seen[s] = c;
            }
            pargrid[i][j] = seen[s];
        }
    }

    c++;
    vector<vector<int>> adj(c);
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> s;
        vector<pii> v;
        for (int j = 0; j < m; j++)
        {
            int val = find_sets(i * m + j, parent);
            if (s.find(val) == s.end())
            {
                s.insert(val);
                v.pb(mp(grid[i][j], pargrid[i][j]));
            }
        }
        sort(v.begin(), v.end(), greater<pii>());
        int len = v.size();
        for (int j = 0; j < len - 1; j++)
            adj[v[j].second].pb(v[j + 1].second);
    }

    for (int j = 0; j < m; j++)
    {
        unordered_set<int> s;
        vector<pii> v;
        for (int i = 0; i < n; i++)
        {
            int val = find_sets(i * m + j, parent);
            if (s.find(val) == s.end())
            {
                s.insert(val);
                v.pb(mp(grid[i][j], pargrid[i][j]));
            }
        }
        sort(v.begin(), v.end(), greater<pii>());
        int len = v.size();
        for (int i = 0; i < len - 1; i++)
            adj[v[i].second].pb(v[i + 1].second);
    }

    vector<int> minval(c, inf);
    auto dfs = [&](int src, auto &&dfs) -> int
    {
        if (minval[src] != inf)
            return minval[src];
        minval[src] = 1;
        int maxa = 0;
        for (int v : adj[src])
            maxa = max(maxa, dfs(v, dfs));
        minval[src] += maxa;
        return minval[src];
    };

    for (int i = 0; i < c; i++)
        if (minval[i] == inf)
            dfs(i, dfs);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pargrid[i][j] = minval[pargrid[i][j]];
        }
    }
    return pargrid;
}

// int main(){
//     vector<vector<int>> v = { { 20, -21, 14 }, { -19, 4, 19 }, { 22, -47, 24 }, {-19, 4, 19 } };
//     vector<vector<int>> temp = ans(v);
//     for(int i=0;i<4;i++)
//         for(int j=0;j<3;j++)
//             cout<<temp[i][j]<<endl;
//     cout<<"Temp"<<endl;
//     return 0;
// }
class Solution
{
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix)
    {
        return ans(matrix);
    }
};