#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define N ((1e5) + 1)
#define pb push_back
#define pf push_front
#define mp make_pair

void initialize(int n, vector<int> &parent, vector<int> &size, unordered_set<int> &s)
{
    parent.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        size[i] = s.find(i) != s.end();
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

int ans(vector<int> &nums)
{
    unordered_set<int> s(nums.begin(), nums.end());
    vector<int> parent, size;
    initialize(N, parent, size, s);
    vector<bool> isprime(N, true);

    for (int i = 2; i < N; i++)
    {
        if (!isprime[i])
            continue;
        for (int j = 2 * i; j < N; j += i)
        {
            isprime[j] = false;
            if (s.find(j) != s.end())
                union_sets(i, j, parent, size);
        }
    }
    return *max_element(size.begin(), size.end());
}

class Solution
{
public:
    int largestComponentSize(vector<int> &nums)
    {
        return ans(nums);
    }
};