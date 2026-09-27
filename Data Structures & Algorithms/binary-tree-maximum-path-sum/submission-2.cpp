class Solution {
public:
    int sum = INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;
        
        int l = max(0,solve(root->left));
        int r = max(0,solve(root->right));
        sum = max(sum,l+r+root->val);
        return root->val + max(l,r);
    }
    
    
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        solve(root);
        return sum;
    }
};