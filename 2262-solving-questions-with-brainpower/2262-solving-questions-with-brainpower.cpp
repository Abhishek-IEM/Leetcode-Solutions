class Solution {
public:
    long long solve(int i, int n, vector<vector<int>>& q, vector<long long> &dp)
    {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        long long taken = q[i][0] + solve(i + q[i][1] + 1, n, q, dp);
        long long not_taken = solve(i + 1, n, q, dp);

        return dp[i] = max(taken, not_taken);
    }

    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> dp(n + 1, -1);
        return solve(0, n, q, dp);
    }
};