#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *ans(vector<ListNode *> &nums)
{
    int n = nums.size();
    ListNode *ans = new ListNode();
    ListNode *head = ans;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (int i = 0; i < n; i++)
        if (nums[i] != nullptr)
            pq.push(mp(nums[i]->val, i));

    if (pq.empty())
        return nullptr;

    while (!pq.empty())
    {
        pii top = pq.top();
        pq.pop();
        head->val = top.first;
        int pos = top.second;

        if (nums[pos]->next != nullptr)
        {
            pq.push(mp(nums[pos]->next->val, pos));
            nums[pos] = nums[pos]->next;
        }
        if (!pq.empty())
        {
            head->next = new ListNode();
            head = head->next;
        }
    }
    return ans;
}

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return ans(lists);
    }
};