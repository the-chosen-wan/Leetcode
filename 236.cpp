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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* ans(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root==nullptr)
        return nullptr;
    
    int val = root->val;
    int pval = p->val;
    int qval = q->val;

    if(pval==val)
        return p;
    if(qval==val)
        return q;
    
    if(pval<val&&qval<val)
        return ans(root->left,p,q);
    if(pval>val&&qval>val)
        return ans(root->right,p,q);
    return root;
}

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return ans(root,p,q);
    }
};
