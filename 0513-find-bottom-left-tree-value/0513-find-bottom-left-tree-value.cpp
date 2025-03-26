class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int bottomLeft = 0;

        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                TreeNode* node = q.front();
                q.pop();

                bottomLeft = node->val;

                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
        }
        return bottomLeft;
    }
};