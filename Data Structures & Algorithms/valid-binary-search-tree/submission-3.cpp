class Solution {
public:

    bool isValid(TreeNode* root, long long low, long long high) {

        if(root == nullptr)
            return true;

        if(root->val <= low || root->val >= high)
            return false;

        bool lT = isValid(root->left, low, root->val);
        bool rT = isValid(root->right, root->val, high);

        return lT && rT;
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};
