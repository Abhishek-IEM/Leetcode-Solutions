class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int even = 0, odd = 0, alter = 1;

        for(int &num : nums)
        {
            if(num % 2 == 0) even++;
            else odd++;
        }

        int parity = nums[0] % 2;

        for(int i = 1; i < n; i++)
        {
            int currParity = nums[i] % 2;
            if(parity != currParity)
            {
                alter++;
                parity = currParity;
            }
        }

        return max({even, odd, alter});
    }
};