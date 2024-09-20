class Solution {
public:
    int level(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + max(level(root->left), level(root->right));
    }
    void nthLevelOrder(TreeNode* root, int curr , int level , vector<int> &v)
    {
        if(root == NULL) return;
        if(curr == level)
        {
            v.push_back(root->val);
            return;
        }
        nthLevelOrder(root->left, curr+1, level, v);
        nthLevelOrder(root->right, curr+1, level, v);
    }
    void lOrder(TreeNode* root, vector<vector<int>> &ans)
    {
        int n = level(root);
        for(int i=1;i<=n;i++)
        {
            vector<int> v;
            nthLevelOrder(root,1,i,v);
            ans.push_back(v);
            cout<<endl;
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        lOrder(root, ans);
        return ans;
    }
};