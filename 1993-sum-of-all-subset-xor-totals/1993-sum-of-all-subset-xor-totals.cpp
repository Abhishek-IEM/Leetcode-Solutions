class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
       int n = nums.size(), ans = 0;

       for(int &num : nums)
       {
            ans |= num;
       }

       return ans << (n - 1);
    }
};