#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// int get_count(TreeNode* tp){
//     if(tp==nullptr)
//         return 0;
//     return 1+get_count(tp->right)+get_count(tp->left);
// }

void get_max(TreeNode* tp){
    if(tp==nullptr)
        return;
    get_max(tp->left);get_max(tp->right);
    int temp = tp->val;
    if(tp->right!=nullptr)
        tp->val = max(temp,tp->right->val+temp);
    if(tp->left!=nullptr)
        tp->val = max(tp->val,tp->left->val+temp);
    return;
}

void find_max(TreeNode* tp,int& maxi){
    if(tp==nullptr)
        return;
    maxi = max(tp->val,maxi);
    find_max(tp->right,maxi);
    find_max(tp->left,maxi);
    return;
}

void find_two_max(TreeNode* tp,int& maxi){
    if(tp==nullptr)
        return;
    if(tp->left==nullptr&&tp->right==nullptr)
        return;
    if(tp->left==nullptr)
        {find_two_max(tp->right,maxi);return;}
    if(tp->right==nullptr)
        {find_two_max(tp->left,maxi);return;}
    int val1 = tp->left->val;
    int val2 = tp->right->val;

    int temp = max(val1,val2);
    if(temp<0)
        temp = tp->val;
    else 
        temp = tp->val - temp;
    maxi = max(val1+val2+temp,maxi);
    find_two_max(tp->right,maxi);
    find_two_max(tp->left,maxi);
    return;
}

int find_max_path(TreeNode* tp){
    get_max(tp);
    int maxi = -1e9;
    find_max(tp,maxi);
    find_two_max(tp,maxi);
    return maxi;
}

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        return find_max_path(root);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    get_max(root);
    cout<<root->val<<endl;
    
}