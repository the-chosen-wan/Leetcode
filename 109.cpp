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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int atend_l(ListNode* head){
    return head->next==nullptr;
}

int len(ListNode* head){
    int c = 0;
    while(!atend_l(head)){
        c++;
        head=head->next;
    }
    return c;
}

void propagate(ListNode* head,TreeNode* root){
    root = new TreeNode();
    int length = len(head);
    if(length==1){
        root->val = head->val;
        return;
    }

    int mid = (length/2)+1;
    ListNode* first=head;ListNode* prev=head;
    for(int i=1;i<mid;i++){
        prev=head;
        head=head->next;
    }

    root->val = head->val;
    prev->next = nullptr;

    propagate(first,root->left);
    propagate(head->next,root->right);
    return;
}

TreeNode* sorted(ListNode* head){
    TreeNode* root;
    propagate(head,root);
    return root;
}

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        return sorted(head);
    }
};