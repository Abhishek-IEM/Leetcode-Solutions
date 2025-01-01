class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        int count0 = 0, count1 = 0, ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0') count0++;
            prefix[i] = count0;
        }

        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '1') count1++;
            suffix[i] = count1;
        }

        for(int i = 0; i < n - 1; i++)
        {
            int sum = prefix[i] + suffix[i + 1];
            ans = max(ans, sum);
        }

        return ans;
    }
};