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
    int count_levels(TreeNode* root)
    {
        int x = 1;
        if(root->left != nullptr) x = max(x,1+count_levels(root->left));
        if(root->right != nullptr) x = max(x,1+count_levels(root->right));
        return x;
    }
    map<TreeNode*,int>mp;
    int count_deep_nodes(TreeNode* root, int level, int deep_level)
    {
        if(level == deep_level) return mp[root] = 1;
        if(root->left != nullptr) mp[root] += count_deep_nodes(root->left,level+1,deep_level);
        if(root->right != nullptr) mp[root] += count_deep_nodes(root->right,level+1,deep_level);
        return mp[root];
    }
    TreeNode* res;
    int min_level = 1;
    void dfs(TreeNode* root, int level, int nodes)
    {
        if(level>min_level && nodes==mp[root])
        {
            min_level = level;
            res = root;
        }
        if(root->left != nullptr) dfs(root->left,level+1,nodes);
        if(root->right != nullptr) dfs(root->right,level+1,nodes);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int levels = count_levels(root);
        int nodes = count_deep_nodes(root,1,levels);
        res = root;
        dfs(root,1,nodes);
        return res;
    }
};