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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int maxSum = INT_MIN;

    int dfs(TreeNode* root) {

        if (root == nullptr)
            return 0;

        // Maximum contribution from left and right
        int leftSum = max(0, dfs(root->left));
        int rightSum = max(0, dfs(root->right));

        // Best path passing through current node
        int currentPath = leftSum + root->val + rightSum;

        // Update global maximum
        maxSum = max(maxSum, currentPath);

        // Return the best path that can be extended by parent
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {

        dfs(root);

        return maxSum;
    }
};