#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
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

void ans(TreeNode *root, int currsum, int &sum)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        sum += (10 * currsum + root->val);
        return;
    }

    currsum = (10 * currsum) + root->val;
    if (root->right != nullptr)
        ans(root->right, currsum, sum);
    if (root->left != nullptr)
        ans(root->left, currsum, sum);
    return;
}

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        ans(root, 0, sum);
        return sum;
    }
};