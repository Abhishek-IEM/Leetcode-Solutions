class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            char c = nums[i][i];
            if(c == '1') ans += '0';
            else ans += '1';
        }
        return ans;
    }
};