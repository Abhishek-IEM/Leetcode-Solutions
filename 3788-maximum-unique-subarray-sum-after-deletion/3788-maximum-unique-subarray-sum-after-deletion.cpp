class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0, neg = INT_MIN;

        unordered_set<int> st;

        for(int &num : nums)
        {
            if(num <= 0) neg = max(neg, num);
            else if(!st.count(num))
            {
                sum += num;
                st.insert(num);
            }
        }

        return sum == 0 ? neg : sum;
    }
};