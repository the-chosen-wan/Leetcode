#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverse(ListNode *phead, ListNode *prev1, int len)
{
    ListNode *head = phead;
    ListNode *curr = head;
    if (curr == nullptr)
        return nullptr;
    ListNode *prev = prev1;
    ListNode *next = nullptr;
    int c = 0;
    while (c < len)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        c++;
    }
    head->next = next;
    if (prev1 != nullptr)
        prev1->next = prev;
    return head;
}

int len(ListNode *head)
{
    int c = 1;
    while (head->next != nullptr)
    {
        head = head->next;
        c++;
    }
    return c;
}

ListNode *reverse_k(ListNode *head, int k)
{
    int n = len(head);
    int groups = n / k;

    int c = 0;
    ListNode *temp = head;
    if (groups > 0)
    {
        while (c < k - 1)
        {
            temp = temp->next;
            c++;
        }
    }
    ListNode *prev = nullptr;
    for (int i = 0; i < groups; i++)
    {
        head = reverse(head, prev, k);
        prev = head;
        head = head->next;
    }
    return temp;
}

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        return reverse_k(head, k);
    }
};