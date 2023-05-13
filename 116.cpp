#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *ans(Node *root)
{
    if (root == nullptr)
        return root;
    queue<pair<int, Node *>> q;
    q.push(mp(0, root));

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        if (!q.empty() && q.front().first == front.first)
            q.front().second->next = front.second;
        if (front.second->right != nullptr)
            q.push(mp(front.first + 1, front.second->right));
        if (front.second->left != nullptr)
            q.push(mp(front.first + 1, front.second->left));
    }
    return root;
}

class Solution
{
public:
    Node *connect(Node *root)
    {
        return ans(root);
    }
};