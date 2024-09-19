class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int x = 1; x <= n; x++) {
            int count = 0;
            // Count how many elements are >= x
            for (int i = 0; i < n; i++) {
                if (nums[i] >= x) {
                    count = n - i;
                    break;
                }
            }
            if (count == x) return x;
        }
        
        return -1;
    }
};