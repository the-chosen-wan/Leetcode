#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
#define N 29
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast") // Comment optimisations for interactive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

struct trie
{
    trie *vec[2];

    trie()
    {
        vec[0] = nullptr;
        vec[1] = nullptr;
    }
};

void insert(trie *t, int num, int pos)
{
    if (pos == -1)
        return;
    int ind = (num & (1 << pos)) != 0 ? 1 : 0;
    if (t->vec[ind] == nullptr)
        t->vec[ind] = new trie();
    insert(t->vec[ind], num, pos - 1);
    return;
}

int maxxor(trie *t, int num, int limit, int pos, bool check)
{
    if (pos == -1)
        return 0;
    int maxa = -1;
    int num_ind = (num & (1 << pos)) != 0 ? 1 : 0;
    int limit_ind = (limit & (1 << pos)) != 0 ? 1 : 0;
    bool new_check = check;
    int temp;

    if (num_ind == 1)
    {
        if (t->vec[0] != nullptr)
        {
            if (limit_ind == 1)
                new_check = true;
            temp = maxxor(t->vec[0], num, limit, pos - 1, new_check);
            if (temp != -1)
                maxa = max(maxa, (1 << pos) + temp);
        }

        if (t->vec[1] != nullptr && (limit_ind != 0 || check))
        {
            temp = maxxor(t->vec[1], num, limit, pos - 1, check);
            if (temp != -1)
                maxa = max(maxa, temp);
        }
    }

    else
    {
        if (t->vec[1] != nullptr && (limit_ind != 0 || check))
        {
            temp = maxxor(t->vec[1], num, limit, pos - 1, check);
            if (temp != -1)
                maxa = max(maxa, (1 << pos) + temp);
        }

        if (t->vec[0] != nullptr)
        {
            if (limit_ind == 1)
                new_check = true;
            temp = maxxor(t->vec[0], num, limit, pos - 1, new_check);
            if (temp != -1)
                maxa = max(maxa, temp);
        }
    }
    return maxa;
}

vector<int> ans(vector<int> &nums, vector<vector<int>> queries)
{
    int n = nums.size();
    trie *t = new trie();

    for (int i = 0; i < n; i++)
        insert(t, nums[i], N);

    vector<int> ans;
    int s = queries.size();
    for (int i = 0; i < s; i++)
    {
        ans.pb(maxxor(t, queries[i][0], queries[i][1], N, false));
    }
    return ans;
}

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        return ans(nums, queries);
    }
};
