#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
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

vector<int> ans(TreeNode *root, int &global)
{
    if (root->right == nullptr && root->left == nullptr)
    {
        global = max(global, root->val);
        return {root->val, root->val, root->val};
    }

    bool leftbst = root->left == nullptr ? true : false;
    bool rightbst = root->right == nullptr ? true : false;
    vector<int> left = {0, root->val, root->val};
    vector<int> right = {0, root->val, root->val};
    vector<int> curr = {-inf, root->val, root->val};

    if (root->left != nullptr)
    {
        left = ans(root->left, global);
        if (root->val > left[2] && left[0] != -inf)
            leftbst = true;
        curr[2] = max(curr[2], left[2]);
        curr[1] = min(curr[1], left[1]);
    }

    if (root->right != nullptr)
    {
        right = ans(root->right, global);
        if (root->val < right[1] && right[0] != -inf)
            rightbst = true;
        curr[2] = max(curr[2], right[2]);
        curr[1] = min(curr[1], right[1]);
    }

    if (leftbst && rightbst)
        curr[0] = max(curr[0], root->val + left[0] + right[0]);

    if (leftbst && rightbst)
    {
        global = max(global, curr[0]);
        return curr;
    }
    return {-inf, curr[1], curr[2]};
}

class Solution
{
public:
    int maxSumBST(TreeNode *root)
    {
        int global = 0;
        ans(root, global);
        return global;
    }
};