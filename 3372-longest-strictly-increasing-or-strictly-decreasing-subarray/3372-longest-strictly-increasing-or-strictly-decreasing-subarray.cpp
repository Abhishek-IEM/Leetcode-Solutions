class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int n = arr.size(), inc = 1, dec = 1, ans1 = 1, ans2 = 1;
        for(int i = 0; i < n - 1; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                inc++;
                ans1 = max(ans1, inc); 
            }
            else inc = 1;
        }
        for(int i = 0; i < n - 1; i++)
        {
            if(arr[i] < arr[i + 1])
            {
                dec++;
                ans2 = max(ans2, dec); 
            }
            else dec = 1;
        }
        return max(ans1, ans2);
    }
};