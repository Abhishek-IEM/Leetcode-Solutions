class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i = 0; i < n; i++) pq.push(nums[i]);
        while(k--)
        {
            int x = pq.top();
            pq.pop();
            x++;
            pq.push(x);
        }
        long long prod = 1;
        while(!pq.empty())
        {
            prod *= pq.top();
            prod = prod % 1000000007;
            pq.pop();
        }
        return prod % 1000000007;
    }
};