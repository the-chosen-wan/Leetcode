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

TreeNode *ans(string s)
{
    int i = 0;
    string t = "";
    int n = s.size();
    while (i < n && s[i] != '-')
    {
        t.pb(s[i]);
        i++;
    }
    int v = stoi(t);
    TreeNode *root = new TreeNode(v);
    stack<pair<TreeNode *, int>> sp;
    sp.push(mp(root, 0));

    int c = 0;
    while (i < n)
    {
        if (s[i] == '-')
        {
            c++;
            i++;
        }
        else
        {
            string num;
            while (i < n && s[i] != '-')
            {
                num.pb(s[i]);
                i++;
            }
            int val = stoi(num);
            TreeNode *temp = new TreeNode(val);
            auto top = sp.top();
            if (c > top.second)
                top.first->left = temp;
            else
            {
                while (top.second >= c)
                {
                    sp.pop();
                    top = sp.top();
                }
                sp.top().first->right = temp;
            }
            sp.push(mp(temp, c));
            c = 0;
        }
    }
    return root;
}

class Solution
{
public:
    TreeNode *recoverFromPreorder(string traversal)
    {
        return ans(traversal);
    }
};