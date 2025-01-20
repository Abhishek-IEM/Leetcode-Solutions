class Solution {
public:
    void preOrder(TreeNode* root, int level, vector<int> &ans)
    {
        if(!root) return;
        if(ans.size() < level) ans.push_back(root->val);
        preOrder(root->right, level + 1, ans);
        preOrder(root->left, level + 1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        preOrder(root, 1, ans);
        return ans;
    }
};