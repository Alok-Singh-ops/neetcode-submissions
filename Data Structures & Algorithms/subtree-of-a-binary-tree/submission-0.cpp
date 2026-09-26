class Solution {
public:

    bool isSame(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;

        if (p == nullptr || q == nullptr)
            return false;

        if (p->val != q->val)
            return false;

        return isSame(p->left, q->left) &&
               isSame(p->right, q->right);
    }

    bool isPresent(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr)
            return false;

        // Start comparing from this node
        if (isSame(root, subRoot))
            return true;

        // Otherwise search left and right
        return isPresent(root->left, subRoot) ||
               isPresent(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return isPresent(root, subRoot);
    }
};