class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), count = 0;
        if(n < 3) return 0;

        sort(begin(nums), end(nums));

        for(int k = n - 1; k >= 2; k--)
        {
            int i = 0, j = k - 1;
            while(i < j)
            {
                if(nums[i] + nums[j] > nums[k])
                {
                    count += (j - i);
                    j--;
                }
                else i++;
            }
        }

        return count;
    }
};