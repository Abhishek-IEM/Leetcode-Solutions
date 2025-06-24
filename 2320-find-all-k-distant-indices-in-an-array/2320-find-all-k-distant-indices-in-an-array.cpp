class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;

        for(int j = 0; j < n; j++)
        {
            if(nums[j] == key){
                int s = max(j - k, 0);
                int e = min(j + k, n - 1);

                if(ans.size() > 0 && ans.back() >= s) s = ans.back() + 1;

                for(int i = s; i <= e; i++) ans.push_back(i); 
            }
        }
        return ans;
    }
};