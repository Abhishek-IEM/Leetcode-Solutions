class Solution {
public:
    int solve(vector<int>& values, int i, int j, int t[51][51])
    {
        if(j - i + 1 < 3) return 0;
        if(t[i][j] != -1) return t[i][j];

        int ans = INT_MAX;

        for(int k = i + 1; k < j; k++)
        {
            int wt = values[i] * values[k] * values[j] + solve(values, i, k, t) + solve(values, k, j, t);
            ans = min(ans, wt);
        }

        return t[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        int t[51][51];
        memset(t, -1, sizeof(t));
        return solve(values, 0, n - 1, t);
    }
};