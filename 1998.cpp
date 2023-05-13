#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair
#define N ((1e5) + 1)

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

bool ans(vector<int> &nums)
{
    vector<bool> prime(N, true);
    vector<int> parent;
    vector<int> rank;
    initialize(N, parent, rank);
    int n = nums.size();
    vector<bool> contains(N, false);
    for (int i = 0; i < n; i++)
        contains[nums[i]] = true;

    for (int i = 2; i < N; i++)
    {
        if (prime[i])
        {
            for (int j = i; j < N; j += i)
            {
                if (contains[j])
                    union_set(j, i, parent, rank);
                prime[j] = false;
            }
        }
    }

    vector<pii> index;
    for (int i = 0; i < n; i++)
        index.pb(mp(nums[i], i));

    sort(index.begin(), index.end());

    for (int i = 0; i < n; i++)
    {
        if (find_parent(index[i].first, parent) != find_parent(nums[i], parent))
            return false;
    }

    return true;
}

class Solution
{
public:
    bool gcdSort(vector<int> &nums)
    {
        return ans(nums);
    }
};