class Solution {
public:
    int KadanesMax(vector<int>& nums, int n)
    {
        int sum = nums[0], maxSum = nums[0];

        for(int i = 1; i < n; i++)
        {
            sum = max(sum + nums[i], nums[i]);
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }

    int KadanesMin(vector<int>& nums, int n)
    {
        int sum = nums[0], minSum = nums[0];

        for(int i = 1; i < n; i++)
        {
            sum = min(sum + nums[i], nums[i]);
            minSum = min(minSum, sum);
        }

        return minSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int i = 0; i< n; i++) sum += nums[i];

        int minSum = KadanesMin(nums, n);
        int maxSum = KadanesMax(nums, n);

        int circSum = sum - minSum;

        if(maxSum > 0) return max(maxSum, circSum);

        return maxSum;
    }
};