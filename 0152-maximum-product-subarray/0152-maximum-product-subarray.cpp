class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0], pro = 1;
        //Forward Pass
        for(int i = 0;i  < n; i++)
        {
            pro *= nums[i];
            maxi = max(pro, maxi);
            if(pro == 0) pro = 1;
        }
        //Reset pro = 1 and do a backward pass
        pro = 1;
        for(int i = n - 1; i >= 0; i--)
        {
            pro *= nums[i];
            maxi = max(pro, maxi);
            if(pro == 0) pro = 1;
        }
        return maxi;
    }
};