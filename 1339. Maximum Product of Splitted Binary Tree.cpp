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
    vector<long long>subtree_sum;
    const int MOD = 1e9+7;
    int dfs(TreeNode* root)
    {
        int x = root->val;
        if(root->left != nullptr) x += dfs(root->left);
        if(root->right != nullptr) x += dfs(root->right);
        subtree_sum.push_back(x);
        return x;
    }
    int maxProduct(TreeNode* root) {
        int x = dfs(root);
        long long res = 0;
        for(auto i:subtree_sum)
        {
            res = max(res,i*(x-i));
        }
        return res%MOD;
    }
};