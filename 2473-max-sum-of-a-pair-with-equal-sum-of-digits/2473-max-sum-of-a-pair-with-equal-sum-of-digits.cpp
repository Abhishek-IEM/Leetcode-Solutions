class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;

        while(num > 0) {
            sum += (num % 10);

            num /= 10;
        }

        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
        int result = -1, n = nums.size();

        int mp[82] = {0};

        for(int i = 0; i < n; i++)
        {
            int digitSum = getDigitSum(nums[i]);

            if(mp[digitSum] > 0) result = max(result, nums[i] + mp[digitSum]);

            mp[digitSum] = max(mp[digitSum], nums[i]);
        }
        return result;
    }
};