class Solution {
public:
    long long solve(int idx, vector<int> &nums, bool iseven, vector<vector<long long>> &dp, int n)
    {
        if(idx >= n) return 0;
        
        if(dp[idx][iseven] != -1) return dp[idx][iseven];

        long long skip = solve(idx + 1, nums, iseven, dp, n);

        long long val = nums[idx];

        if(iseven == false) val = -val;

        long long take = val + solve(idx + 1, nums, !iseven, dp, n);

        return dp[idx][iseven] = max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(0, nums, true, dp, n);
    }
};