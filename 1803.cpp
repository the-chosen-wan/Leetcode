#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair
#define N 15

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

int count(trie *t, int num, int pos, int limit)
{
    int result = 0;
    if (pos == -1)
        return t->leaf_count;
    if (t->one != nullptr)
    {
        int val = ((num ^ (1 << pos)) & (1 << pos)) == 0 ? 0 : 1;
        if (val == 0 && ((limit & (1 << pos)) == 0))
            result += count(t->one, num, pos - 1, limit);
        if (val == 1 && ((limit & (1 << pos)) == (1 << pos)))
            result += count(t->one, num, pos - 1, limit);
        if (val == 0 && ((limit & (1 << pos)) == (1 << pos)))
            result += t->one->leaf_count;
    }

    if (t->zero != nullptr)
    {
        int val = (num & (1 << pos)) == 0 ? 0 : 1;
        if (val == 0 && ((limit & (1 << pos)) == 0))
            result += count(t->zero, num, pos - 1, limit);
        if (val == 1 && ((limit & (1 << pos)) == (1 << pos)))
            result += count(t->zero, num, pos - 1, limit);
        if (val == 0 && ((limit & (1 << pos)) == (1 << pos)))
            result += t->zero->leaf_count;
    }

    return result;
}

int ans(vector<int> &nums, int low, int high)
{
    trie *t = new trie();
    insert(t, nums[0], N);

    int low1 = 0;
    int high1 = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        low1 += count(t, nums[i], N, low - 1);
        high1 += count(t, nums[i], N, high);
        insert(t, nums[i], N);
    }
    return high1 - low1;
}

class Solution
{
public:
    int countPairs(vector<int> &nums, int low, int high)
    {
        return ans(nums, low, high);
    }
};
