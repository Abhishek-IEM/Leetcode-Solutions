class Solution {
public:
    vector<vector<int> > dp;
    int helper(int i, vector<int>& coins, int amount)
    {
        if(i == coins.size())
        {
            if(amount == 0) return 0;
            else return INT_MAX;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        if(amount - coins[i] < 0)
        {
            return dp[i][amount] = helper(i + 1, coins, amount);
        }
        else
        {
            long long take = 1LL + helper(i, coins, amount - coins[i]);
            long long leave = helper(i + 1, coins, amount);
            return dp[i][amount] = min(take, leave);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size(), vector<int> (amount + 1, -1));
        int ans = helper(0, coins, amount);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};