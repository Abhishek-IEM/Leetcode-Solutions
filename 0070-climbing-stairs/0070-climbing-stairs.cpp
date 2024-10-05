class Solution {
public:
    int climb(vector<int>& dp, int n)
    {
        if(n <= 2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = climb(dp, n - 1) + climb(dp, n - 2);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return climb(dp, n);
    }
};