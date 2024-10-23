class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root){
       if(root == NULL) return root;
       queue<TreeNode*> q;
       q.push(root);
       vector<int> levelSum;

       while(!q.empty())
       {
            int currLevelSum = 0;
            int n = q.size();
            while(n--)
            {
                TreeNode* curr = q.front();
                q.pop();
                currLevelSum += curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            levelSum.push_back(currLevelSum);
        }
        q.push(root);
        int i = 1;
        root->val = 0;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                TreeNode* curr = q.front();
                q.pop();
                int siblingSum = curr->left != NULL ? curr->left->val : 0;
                siblingSum += curr->right != NULL ? curr->right->val : 0;
                if(curr->left)
                {
                    curr->left->val = levelSum[i] - siblingSum;
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    curr->right->val = levelSum[i] - siblingSum;
                    q.push(curr->right);
                }
            }
            i++;
        } 
        return root;
    }
};