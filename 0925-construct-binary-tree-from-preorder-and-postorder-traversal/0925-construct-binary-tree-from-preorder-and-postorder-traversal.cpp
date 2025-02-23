class Solution {
public:
    TreeNode* solve(int prest, int postst, int preend, vector<int>& preorder, vector<int>& postorder, unordered_map<int, int> &mp)
    {
        if(prest > preend) return NULL;

        TreeNode* root = new TreeNode(preorder[prest]);
        if(prest == preend) return root;

        int nextnode = preorder[prest + 1];

        int j = mp[nextnode];

        int num = j - postst + 1;

        root->left = solve(prest + 1, postst, prest + num, preorder, postorder, mp);
        root->right = solve(prest + num + 1, j + 1, preend, preorder, postorder, mp);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> mp;

        int n = postorder.size();

        for(int i = 0; i < n; i++) mp[postorder[i]] = i;

        return solve(0, 0, n - 1, preorder, postorder, mp);
    }
};