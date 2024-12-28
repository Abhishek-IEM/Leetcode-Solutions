class Solution {
public:
    int t[200001][4];

    int helper(vector<int>& subarray, int count, int i, int k)
    {
        if(count == 0) return 0;
        if(i >= subarray.size()) return INT_MIN;

        if(t[i][count] != -1) return t[i][count];

        int take = subarray[i] + helper(subarray, count - 1, i + k, k);
        int not_take = helper(subarray, count, i + 1, k);

        return t[i][count] = max(take, not_take);
    }

    void solve(vector<int>& subarray, int count, int i, int k, vector<int>& result)
    {
        if(count == 0) return;
        if(i >= subarray.size()) return;

        int take_i = subarray[i] + helper(subarray, count - 1, i + k, k);
        int not_take_i = helper(subarray, count, i + 1, k);

        if(take_i >= not_take_i)
        {
            result.push_back(i);
            solve(subarray, count - 1, i + k, k, result);
        }
        else solve(subarray, count, i + 1, k, result);
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(t, -1, sizeof(t));
        int i = 0, j = 0, windowSum = 0;
        vector<int> subarray;
        while(j < nums.size())
        {
            windowSum += nums[j];

            if(j - i + 1 == k)
            {
                subarray.push_back(windowSum);
                windowSum -= nums[i];
                i++;
            }

            j++;
        }
        vector<int> result;
        solve(subarray, 3, 0, k, result);
        return result;
    }
};