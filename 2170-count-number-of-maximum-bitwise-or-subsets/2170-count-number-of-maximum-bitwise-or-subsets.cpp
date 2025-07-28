class Solution {
public:
    int countSubsets(int idx, int currOr, vector<int>& nums, int maxOr)
    {
        if(idx == nums.size())
        {
            if(currOr == maxOr) return 1;
            return 0;
        }

        int take = countSubsets(idx + 1, currOr | nums[idx], nums, maxOr);
        int nottake = countSubsets(idx + 1, currOr, nums, maxOr);

        return take + nottake;
    } 
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;

        for(int &num : nums) maxOr |= num;

        int n = nums.size();

        int currOr = 0;

        return countSubsets(0, currOr, nums, maxOr);
    }
};