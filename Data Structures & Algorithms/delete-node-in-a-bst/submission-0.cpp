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

    TreeNode* findMin(TreeNode* root) {

        while (root->left != nullptr) {
            root = root->left;
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        // Key not found
        if (root == nullptr)
            return nullptr;

        // Search left
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        // Search right
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        // Found the node
        else {

            // No left child
            if (root->left == nullptr) {
                return root->right;
            }

            // No right child
            if (root->right == nullptr) {
                return root->left;
            }

            // Two children
            TreeNode* successor = findMin(root->right);

            root->val = successor->val;

            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }
};