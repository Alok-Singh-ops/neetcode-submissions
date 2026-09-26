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
    int diameter = 0;
    int f(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int lf = f(root->left);
        int rf = f(root->right);
        diameter = max(diameter,lf+rf);
        return 1+max(lf,rf);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        f(root);
        return diameter;
    }
};
