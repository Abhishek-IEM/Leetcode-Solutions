class Solution {
public:
    int dp[51];
    int solve(int i, string &s, unordered_set<string> &mp, int &n)
    {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int take = 1 + solve(i + 1, s, mp, n);
        for(int j = i; j < n; j++)
        {
            string str = s.substr(i, j - i + 1);
            if(mp.count(str))
            {
                take = min(take, solve(j + 1, s, mp, n));
            }
        }
        return dp[i] = take;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        unordered_set<string> mp(dictionary.begin(), dictionary.end());
        return solve(0,s, mp, n);
    }
};