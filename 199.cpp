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

vector<int> ans(TreeNode *root)
{
    queue<pair<int, TreeNode *>> q;
    vector<pii> ans;
    if (root == nullptr)
        return {};
    q.push(mp(0, root));
    ans.pb(mp(0, root->val));

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        if (front.first > ans.back().first)
            ans.pb(mp(front.first, front.second->val));
        if (front.second->right != nullptr)
            q.push(mp(front.first + 1, front.second->right));
        if (front.second->left != nullptr)
            q.push(mp(front.first + 1, front.second->left));
    }

    vector<int> ret;
    for (pii &e : ans)
        ret.pb(e.second);
    return ret;
}

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        return ans(root);
    }
};