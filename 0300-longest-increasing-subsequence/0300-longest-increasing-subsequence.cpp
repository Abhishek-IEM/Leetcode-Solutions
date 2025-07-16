class Solution {
public:
    int solve(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
    {
        int n = nums.size();
        if(j == n) return 0;

        if(dp[i + 1][j] != -1) return dp[i + 1][j];

        int take = 0;
        if(i == -1 || nums[i] < nums[j])
        {
            take = 1 + solve(nums, j, j + 1, dp);
        }
        int nottake = solve(nums, i, j + 1, dp);

        return dp[i + 1][j] = max(take, nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (n, -1));
        return solve(nums, -1, 0, dp);
    }
};