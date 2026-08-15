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

    int search(vector<int>& inorder, int left, int right, int value) {

        for (int i = left; i <= right; i++) {
            if (inorder[i] == value)
                return i;
        }

        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                     int& preIdx, int left, int right) {

        if (left > right) {
            return nullptr;
        }

        // First element of preorder is the root
        TreeNode* root = new TreeNode(preorder[preIdx]);
        preIdx++;

        // Find root in inorder
        int inIdx = search(inorder, left, right, root->val);

        // Everything before root in inorder = left subtree
        root->left = helper(preorder, inorder,
                            preIdx, left, inIdx - 1);

        // Everything after root in inorder = right subtree
        root->right = helper(preorder, inorder,
                             preIdx, inIdx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int preIdx = 0;

        return helper(preorder, inorder,
                      preIdx, 0, inorder.size() - 1);
    }
};