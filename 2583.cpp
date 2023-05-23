#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

ll ans(TreeNode* root,int k){
    queue<pair<int,TreeNode*>> q;

    q.push(mp(0,root));
    map<int,ll> summa;

    while(!q.empty()){
        auto temp = q.front();
        q.pop();

        summa[temp.first]+=temp.second->val;

        if(temp.second->left!=nullptr)
            q.push(mp(temp.first+1,temp.second->left));

        if(temp.second->right!=nullptr)
            q.push(mp(temp.first+1,temp.second->right));
    }
    
    vector<ll> ans;

    for(auto t:summa)
        ans.pb(t.second);
    
    if(summa.size()<k)
        return -1;

    sort(ans.begin(),ans.end(),greater<ll>());
    return ans[k-1];
}

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        return ans(root,k);
    }
};