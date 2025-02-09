class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
        {
            int diff = nums[i] - i;
            int totalPairs = i;
            int goodPairs = mp[diff];

            ans += totalPairs - goodPairs;

            mp[diff]++;
        }
        return ans;
    }
};