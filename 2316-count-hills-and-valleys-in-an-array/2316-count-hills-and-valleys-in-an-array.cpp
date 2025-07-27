class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 1, count = 0;

        while(j + 1 < n)
        {
            if((nums[i] < nums[j] && nums[j] > nums[j + 1]) || (nums[i] > nums[j] && nums[j] < nums[j + 1])){
                count++;
                i = j;
            }
            j++;
        }

        return count;
    }
};