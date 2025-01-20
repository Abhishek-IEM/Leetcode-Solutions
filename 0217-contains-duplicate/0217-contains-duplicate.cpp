class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) mp[nums[i]]++;

        for(auto x : mp)
        {
            int a = x.first, b = x.second;
            if(b >= 2) return true;
        }
        return false;
    }
};