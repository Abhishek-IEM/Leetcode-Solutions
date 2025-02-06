class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++) pq.push(nums[i]);
        return pq.top();
    }
};