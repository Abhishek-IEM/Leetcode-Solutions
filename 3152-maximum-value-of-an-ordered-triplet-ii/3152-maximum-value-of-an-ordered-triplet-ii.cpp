class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
        }
        for(int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], nums[i+1]);
        }

        long long result = 0;
        for (int j = 1; j < n - 1; j++) {
            result = max(result, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
        }
        return result;
    }
};