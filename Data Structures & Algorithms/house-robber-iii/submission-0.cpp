/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    pair<int, int> dfs(TreeNode* root) {

        if (root == nullptr)
            return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // If we rob current node,
        // we cannot rob its children.
        int rob = root->val + left.second + right.second;

        // If we don't rob current node,
        // we can choose whether to rob each child or not.
        int skip = max(left.first, left.second)
                 + max(right.first, right.second);

        return {rob, skip};
    }

    int rob(TreeNode* root) {

        auto result = dfs(root);

        return max(result.first, result.second);
    }
};