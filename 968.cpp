#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int c = 0;

int count_nodes(TreeNode *root)
{
    root->val = c;
    c++;
    int nodes = 1;
    if (root->left != nullptr)
        nodes += count_nodes(root->left);
    if (root->right != nullptr)
        nodes += count_nodes(root->right);
    return nodes;
}

void dfs(TreeNode *root, vector<int> &with, vector<int> &without)
{
    int wit = 1;
    int witout = inf;

    if (root->left != nullptr)
    {
        witout = 0;
        dfs(root->left, with, without);
        wit += without[root->left->val];
        witout += min(with[root->left->val], without[root->left->val]);
    }

    if (root->right != nullptr)
    {
        if (witout == inf)
            witout = 0;
        dfs(root->right, with, without);
        wit += without[root->right->val];
        witout += min(with[root->right->val], without[root->right->val]);
    }
    with[root->val] = wit;
    without[root->val] = witout;
}

int mini(TreeNode *root)
{
    int val = count_nodes(root);
    vector<int> with(val, 1);
    vector<int> without(val, inf);
    dfs(root, with, without);
    return min(with[root->val], without[root->val]);
}

class Solution
{
public:
    int minCameraCover(TreeNode *root)
    {
        return mini(root);
    }
};