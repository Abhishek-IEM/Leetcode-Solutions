class Solution {
public:
    int OneDArray(vector<int>& vec)
    {
        int cons = 0, sub = 0;

        for(int &val : vec)
        {
            if(val == 0) cons = 0;
            else cons++;

            sub += cons;
        }
        return sub;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), ans = 0;

        for(int sr = 0; sr < m; sr++)
        {
            vector<int> vec(n, 1);
            for(int er = sr; er < m; er++)
            {
                for(int col = 0; col < n; col++)
                {
                    vec[col] = vec[col] & mat[er][col];
                }
                ans += OneDArray(vec);
            }
        }
        return ans;
    }
};