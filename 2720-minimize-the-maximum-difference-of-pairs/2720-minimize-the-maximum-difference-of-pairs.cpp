class Solution {
public:
    bool isValid(vector<int>& nums, int mid, int p)
    {
        int n = nums.size(), count = 0, i = 0;

        while(i < n - 1)
        {
            if(nums[i + 1] - nums[i] <= mid){
                count++;
                i += 2;
            }
            else i++;
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size(), ans = INT_MAX;

        sort(nums.begin(), nums.end());

        int l = 0, r = nums[n - 1] - nums[0];

        while(l <= r)
        {
            int mid = l + (r - l)/2;

            if(isValid(nums, mid, p)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};