class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length(), black = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1') black++;
            else ans += black;
        }
        return ans;
    }
};