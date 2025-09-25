class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col, int n, vector<vector<int>> &dp) {
        if(row == n - 1) return triangle[row][col];

        if(dp[row][col] != INT_MAX) return dp[row][col];

        int sum = triangle[row][col] + min(solve(triangle, row + 1, col, n, dp), solve(triangle, row + 1, col + 1, n, dp));

        return dp[row][col] = sum;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(201, vector<int> (201, INT_MAX));
        return solve(triangle, 0, 0, n, dp);
    }
};