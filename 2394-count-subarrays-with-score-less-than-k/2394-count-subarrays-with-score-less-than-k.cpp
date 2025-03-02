class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size(), sum = 0, score = 0, start = 0, end = 0, count = 0;

        while(end < n)
        {
            sum += nums[end];
            score = sum * (end - start + 1);

            while(start <= end && score >= k)
            {
                sum -= nums[start];
                start++;
                score = sum * (end - start + 1);
            }
            count += end - start + 1;
            end++;
        }
        return count;
    }
};