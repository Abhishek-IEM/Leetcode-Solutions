class Solution {
public:
    vector<vector<int> > dp;
    bool helper(int i, vector<int>& nums, int sum, int target) {
        if(i == nums.size())
        {
            if(sum == target) return true;
            else return false;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        int take = helper(i + 1, nums, sum + nums[i], target);
        int leave = helper(i + 1, nums, sum, target);
        return dp[i][sum] = take || leave;
    }
    
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int ele : nums) totalSum += ele;
        if(totalSum % 2 != 0) return false;
        int target = totalSum/2;
        dp.resize(nums.size(), vector<int>(totalSum, -1));
        return helper(0, nums, 0, target);
    }
};