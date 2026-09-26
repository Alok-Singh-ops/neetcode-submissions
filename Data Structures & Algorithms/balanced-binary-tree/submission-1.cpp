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
    bool bal = true;
    int solve(TreeNode* root){
        if(root == nullptr)
            return 0;

        int lHeight = solve(root->left);
        int rHeight = solve(root->right);
       bal = bal && (abs(lHeight - rHeight) <= 1);
        return 1 + max(lHeight,rHeight);
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        solve(root);
        return bal;
    }
};
