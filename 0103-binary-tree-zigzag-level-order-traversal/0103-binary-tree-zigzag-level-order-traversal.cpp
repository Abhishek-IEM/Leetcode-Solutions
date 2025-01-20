class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int n = q.size();
            vector<int> v;
            level++;
            while(n--)
            {
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if (level % 2 == 0) {
            reverse(v.begin(), v.end());
        }
            ans.push_back(v);
        }
        return ans;
    }
};