class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        int N = n * n;

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                mp[grid[i][j]]++;
            }
        }

        int a = -1, b = -1;

        for(int num = 1; num <= N; num++)
        {
            if(!mp.count(num)) b = num;
            else if(mp[num] == 2) a = num;

            if(a != -1 && b != -1) break;
        }
        return {a, b};
    }
};