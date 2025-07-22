class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int sum = 0, n = nums.size();

        int i = 0, j = 0, ans = 0;

        while(j < n)
        {
            if(!st.count(nums[j]))
            {
                sum += nums[j];
                ans = max(ans, sum);
                st.insert(nums[j]);
                j++;
            }
            else{
                while(i < n && st.count(nums[j])){
                    sum -= nums[i];
                    st.erase(nums[i]);
                    i++;
                }
            }
        }

        return ans;
    }
};