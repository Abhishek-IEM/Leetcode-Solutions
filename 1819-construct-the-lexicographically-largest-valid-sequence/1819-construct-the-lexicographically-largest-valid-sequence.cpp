class Solution {
public:
    bool solve(int i, int n, vector<int> &ans, vector<bool> &used)
    {
        if(i >= ans.size()) return true;

        if(ans[i] != -1) return solve(i + 1, n, ans, used);

        for(int num = n; num >= 1; num--)
        {
            if(used[num]) continue;
            used[num] = true;
            ans[i] = num;
            
            if(num == 1){
                if(solve(i + 1, n, ans, used) == true) return true;
            }
            else{
                int j = i + ans[i];
                if(j < ans.size() && ans[j] == -1){
                    ans[j] = num;
                    if(solve(i + 1, n, ans, used) == true) return true;
                    ans[j] = -1;
                }
            }
            used[num] = false;
            ans[i] = -1;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1, -1);
        vector<bool> used(n + 1, false);
        solve(0, n, ans, used);
        return ans;
    }
};