class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin(), banned.end());
        int count = 0, sum = 0;
        for(int num = 1; num <= n; num++)
        {
            if(st.count(num)) continue;
            if(sum + num <= maxSum)
            {
                sum += num;
                count++;
            }
            else break;
        }
        return count;
    }
};