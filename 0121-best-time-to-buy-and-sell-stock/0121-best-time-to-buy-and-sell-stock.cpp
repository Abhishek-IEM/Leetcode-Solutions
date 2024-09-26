class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int profit = 0, mini = arr[0];
        for(int i = 1; i < n; i++)
        {
            int diff = arr[i] - mini;
            profit = max(profit, diff);
            mini = min(arr[i], mini);
        }
        return profit;
    }
};