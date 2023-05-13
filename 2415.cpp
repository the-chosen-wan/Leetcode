#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, int>;
const int inf = (1e9) + 7;
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

void reverse(TreeNode* root,bool flag){
    if(root==nullptr)
        return;
    if(flag)
        swap(root->left->val,root->right->val);
    reverse(root->left,!flag);
    reverse(root->right,!flag);
    return;
}

class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        reverse(root,true);
        return root;
    }
};
