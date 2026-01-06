#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    map<int,int>level_sum;
    int level = 1;
    int mx = INT_MIN;
    void dfs(TreeNode* root) {
        level_sum[level]+=(root->val);
        level++;
        if(root->left != nullptr) dfs(root->left);
        if(root->right != nullptr) dfs(root->right);
        level--;
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root);
        int res = 0;
        for(auto i:level_sum)
        {
            if(i.second>mx)
            {
                mx = i.second;
                res = i.first;
            }
        }
        return res;
    }
};