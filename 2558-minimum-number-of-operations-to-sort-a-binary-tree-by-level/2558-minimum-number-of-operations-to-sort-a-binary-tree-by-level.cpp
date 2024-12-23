class Solution {
public:
    int countMinSwap(vector<int> &vec)
    {
        int swaps = 0;
        vector<int> sortedVec(vec.begin(), vec.end());
        sort(sortedVec.begin(), sortedVec.end());
        unordered_map<int, int> mp;
        for(int i = 0; i < vec.size(); i++)
        {
            mp[vec[i]] = i;
        }
        for(int i = 0; i < vec.size(); i++)
        {
            if(vec[i] == sortedVec[i]) continue;
            int currIdx = mp[sortedVec[i]];
            mp[vec[i]] = currIdx;
            mp[vec[currIdx]] = i;
            swap(vec[currIdx], vec[i]);
            swaps++;
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int result = 0;
        while(!q.empty())
        {
            int n = q.size();
            vector<int> vec;
            while(n--)
            {
                TreeNode* temp = q.front();
                q.pop();
                vec.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            result += countMinSwap(vec);
        }
        return result;
    }
};