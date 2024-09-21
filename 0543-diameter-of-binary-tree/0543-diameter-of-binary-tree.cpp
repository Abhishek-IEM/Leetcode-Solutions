class Solution {
public:
    int levels(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }

    void helper(TreeNode* root, int &maxDia)
    {
        if(root == NULL) return;
        int dia = levels(root->left) + levels(root->right);
        maxDia = max(dia, maxDia);
        helper(root->left, maxDia);
        helper(root->right, maxDia);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        helper(root, maxDia);
        return maxDia;
    }
}; 