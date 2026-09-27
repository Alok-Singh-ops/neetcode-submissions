class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> temp;

        if(root == nullptr)
            return temp;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int size = q.size();

            vector<int> level;

            for(int i = 0; i < size; i++) {

                TreeNode* frontNode = q.front();
                q.pop();

                level.push_back(frontNode->val);

                if(frontNode->left != nullptr)
                    q.push(frontNode->left);

                if(frontNode->right != nullptr)
                    q.push(frontNode->right);
            }

            temp.push_back(level);
        }

        return temp;
    }
};