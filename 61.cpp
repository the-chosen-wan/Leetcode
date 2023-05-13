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

int size(ListNode *head)
{
    int c = 0;
    while (head != nullptr)
    {
        c++;
        head = head->next;
    }
    return c;
}

void rotate(ListNode **phead)
{
    ListNode *tail = *phead;
    ListNode *prev = nullptr;

    while (tail->next != nullptr)
    {
        prev = tail;
        tail = tail->next;
    }
    prev->next = nullptr;
    tail->next = *phead;
    *phead = tail;
    return;
}

ListNode *rotate(ListNode *head, int k)
{
    int len = size(head);
    if (len <= 1)
        return head;

    k %= len;
    for (int i = 0; i < k; i++)
        rotate(&head);
    return head;
}

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        return rotate(head, k);
    }
};