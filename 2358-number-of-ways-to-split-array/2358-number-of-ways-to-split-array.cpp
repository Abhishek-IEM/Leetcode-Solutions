class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), split = 0;
        long long sum = 0, leftSum = 0, rightSum = 0;
        for(int &num : nums) sum += num;
        for(int i = 0; i  < n - 1; i++)
        {
            leftSum += nums[i];
            rightSum = sum - leftSum;
            if(leftSum >= rightSum) split++;
        }
        return split;
    }
};