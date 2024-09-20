class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n,-1);
        vector<int> a(2*n,-1);
        stack<int> st;
        for(int i=0;i<2*n-1;i++)
        {
            a[i] = nums[i%n];
        }
        for(int i=0;i<2*n-1;i++)
        {
            while(!st.empty() && a[st.top()] < a[i])
            {
                ans[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
        vector<int> x(n, -1);
        for(int i=0;i<n;i++)
        {
            x[i] = ans[i];
        }
        return x;
    }
};