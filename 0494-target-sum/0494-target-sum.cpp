class Solution {
public:
    int helper(int i, vector<int>& nums, int sum, int target) {
        if(i == nums.size())
        {
            if(sum == target) return 1;
            else return 0;
        }
        int add = helper(i + 1, nums, sum + nums[i], target);
        int sub = helper(i + 1, nums, sum - nums[i], target);
        return add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(0, nums, 0, target);
    }
};