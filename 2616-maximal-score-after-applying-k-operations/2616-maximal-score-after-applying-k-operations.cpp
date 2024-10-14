class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++) pq.push(nums[i]);
        while(k--)
        {
            int x = pq.top();
            pq.pop();
            ans += x;
            x = ceil(x/3.0);
            pq.push(x);
        }
        return ans;
    }
};