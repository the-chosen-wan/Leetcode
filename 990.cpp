#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
#define N 26

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

bool ans(vector<string> &eqs)
{
    vector<string> equals, notequals;
    int n = eqs.size();

    for (int i = 0; i < n; i++)
    {
        if (eqs[i][1] == '=')
            equals.pb(eqs[i]);
        else
            notequals.pb(eqs[i]);
    }

    vector<int> parent, size;
    initialize(N, parent, size);

    for (string &s : equals)
    {
        int n1 = s[0] - 'a';
        int n2 = s[3] - 'a';
        union_sets(n1, n2, parent, size);
    }

    for (string &s : notequals)
    {
        int n1 = s[0] - 'a';
        int n2 = s[3] - 'a';
        if (find_sets(n1, parent) == find_sets(n2, parent)){
            return false;
        }
    }

    return true;
}

class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        return ans(equations);
    }
};

int main(){
    vector<string> s = {"c==c", "b==d", "x!=z" };
    cout<<ans(s)<<endl;
}