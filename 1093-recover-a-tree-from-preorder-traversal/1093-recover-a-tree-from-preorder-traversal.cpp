class Solution {
public:
    TreeNode* solve(string &s, int &i, int depth, int &n)
    {
        if(i >= n) return NULL;

        int j = i;

        while(j < n && s[j] == '-') j++;

        int dash = j - i;
        if(depth != dash) return NULL;

        i += dash;

        int num = 0;

        while(i < n && isdigit(s[i]))
        {
            num = (num * 10) + (s[i] - '0');
            i++;
        }

        TreeNode* root = new TreeNode(num);
        root->left = solve(s, i, depth + 1, n);
        root->right = solve(s, i, depth + 1, n);

        return root;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.length();
        int i = 0;
        return solve(traversal, i, 0, n);
    }
};