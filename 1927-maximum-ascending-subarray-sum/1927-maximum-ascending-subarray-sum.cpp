class Solution {
public:
    int maxAscendingSum(vector<int>& arr) {
        int n = arr.size();
        int sum = arr[0];
        int maxSum = arr[0];
        for(int i = 1; i < n ; i++)
        {
            if(arr[i] > arr[i - 1]) sum += arr[i];
            else sum = arr[i];

            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};