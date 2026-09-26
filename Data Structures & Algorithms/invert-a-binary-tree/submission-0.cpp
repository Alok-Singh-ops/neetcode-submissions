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

    TreeNode* invert(TreeNode* root){
        if(root == nullptr || root == nullptr){
            return nullptr;
        }
        // TreeNode* temp = root->left;
        // root->left = root->right;
        // root->right = temp;
        TreeNode* lSwap = invert(root->left);
        TreeNode* rSwap = invert(root->right);
        root->left = rSwap;
        root->right = lSwap;

        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
};
