#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
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

 using ptree = pair<TreeNode* , int>;

 int ans(TreeNode* root){
    queue<pair<TreeNode* , int>> q;
    q.push(make_pair(root,0));
    unordered_map<int,vector<int>> levelmap;

    while(!q.empty()){
        ptree front = q.front();
        q.pop();
        levelmap[front.second].pb(front.first->val);

        if(front.first->left!=nullptr){
            q.push(make_pair(front.first->left,front.second+1));
        }

        if(front.first->right!=nullptr){
            q.push(make_pair(front.first->right,front.second+1));
        }
    }

    auto findswap = [&](vector<int>& vec)->int{
        unordered_map<int,int> indices;
        int s = vec.size();

        for(int i=0;i<s;i++)
            indices[vec[i]] = i;

        vector<int> temp(vec);

        sort(temp.begin(),temp.end());
        int cnt = 0;

        for(int i=0;i<s;i++){
            if(vec[i]==temp[i])
                continue;
            cnt++;

            int ind = indices[temp[i]];
            indices[temp[i]] = i;
            indices[vec[i]] = ind;
            swap(vec[i],vec[ind]);
        }
        return cnt;
    };

    int totcnt = 0;
    for(pair<int,vector<int>> p:levelmap){
        totcnt+=findswap(p.second);
    }
    return totcnt;
 }

 class Solution {
public:
    int minimumOperations(TreeNode* root) {
        return ans(root);
    }
};
