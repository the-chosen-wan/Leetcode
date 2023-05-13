#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll inf = 1e15;
#define pb push_back
#define mp make_pair

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<ll> ans(TreeNode *root)
{
    bool flag = false;
    ll mini = inf;
    ll maxa = -inf;
    if (root->right != nullptr)
    {
        vector<ll> right = ans(root->right);
        if (root->val >= right[2] || right[0] == 0)
            flag = true;
        maxa = max<ll>(maxa, right[1]);
        mini = min<ll>(mini, right[2]);
    }
    if (root->left != nullptr)
    {
        vector<ll> left = ans(root->left);
        if (root->val <= left[1] || left[0] == 0)
            flag = true;
        maxa = max<ll>(maxa, left[1]);
        mini = min<ll>(mini, left[2]);
    }
    maxa = max<ll>(root->val, maxa);
    mini = min<ll>(root->val, mini);
    if (!flag)
        return {1, maxa, mini};
    return {0, maxa, mini};
}

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return ans(root)[0];
    }
};