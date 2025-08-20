class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp)
    {
        if(i >= matrix.size() || j >= matrix[0].size()) return 0;

        if(matrix[i][j] == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(matrix, i + 1, j, dp);
        int diag = solve(matrix, i + 1, j + 1, dp);
        int below = solve(matrix, i, j + 1, dp);

        return dp[i][j] = 1 + min({right, diag, below});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 1){
                    ans += solve(matrix, i, j, dp);
                }
            }
        }

        return ans;
    }
};