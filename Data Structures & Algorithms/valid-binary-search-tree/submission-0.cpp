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

    bool validate(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {

        if (root == nullptr)
            return true;

        // root must be greater than minNode
        if (minNode != nullptr && root->val <= minNode->val)
            return false;

        // root must be smaller than maxNode
        if (maxNode != nullptr && root->val >= maxNode->val)
            return false;

        return validate(root->left, minNode, root) &&
               validate(root->right, root, maxNode);
    }

    bool isValidBST(TreeNode* root) {

        return validate(root, nullptr, nullptr);
    }
};
