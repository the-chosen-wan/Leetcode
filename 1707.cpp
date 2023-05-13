#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair
#define N 30

struct trie
{
    int leaf_count;
    trie *zero;
    trie *one;
    int end_count;

    trie()
    {
        this->zero = nullptr;
        this->one = nullptr;
        this->leaf_count = 0;
        this->end_count = 0;
    }
};

void insert(trie *t, int num, int pos)
{
    if (pos == -1)
    {
        t->leaf_count++;
        return;
    }

    if ((num & (1 << pos)) != 0)
    {
        if (t->one == nullptr)
            t->one = new trie();
        insert(t->one, num, pos - 1);
    }
    else
    {
        if (t->zero == nullptr)
            t->zero = new trie();
        insert(t->zero, num, pos - 1);
    }

    int sum = 0;
    if (t->one != nullptr)
        sum += t->one->leaf_count;
    if (t->zero != nullptr)
        sum += t->zero->leaf_count;
    // sum+=t->end_count;
    t->leaf_count = sum;
    return;
}

int ret(trie *t, int num, int pos, int limit, bool check)
{
    if (pos == -1)
        return 0;
    int maxa = -1;
    int val = (limit & (1 << pos));
    int numval = (num & (1 << pos));
    bool new_check = check;

    if (numval != 0)
    {
        if (t->zero != nullptr)
        {
            if (val != 0)
                new_check = true;
            int temp = ret(t->zero, num, pos - 1, limit, new_check);
            if (temp != -1)
                return (1 << pos) + temp;
        }
        if (t->one != nullptr && (val != 0 || check))
        {

            int temp = ret(t->one, num, pos - 1, limit, check);
            if (temp != -1)
                maxa = max(maxa, temp);
        }
    }
    else
    {
        if (t->one != nullptr && (val != 0 || check))
        {
            int temp = ret(t->one, num, pos - 1, limit, check);
            if (temp != -1)
                return (1 << pos) + temp;
        }
        if (t->zero != nullptr)
        {
            if (val != 0)
                new_check = true;
            int temp = ret(t->zero, num, pos - 1, limit, new_check);
            if (temp != -1)
                maxa = max(maxa, temp);
        }
    }
    return maxa;
}

vector<int> maxa(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    trie *t = new trie();

    for (int i = 0; i < n; i++)
        insert(t, nums[i], N);

    vector<int> ans;
    for (vector<int> &v : queries)
    {
        ans.pb(ret(t, v[0], N, v[1], false));
    }
    return ans;
}

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        return maxa(nums, queries);
    }
};