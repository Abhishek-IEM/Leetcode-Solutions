class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid) 
    {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        int fish = grid[i][j];
        grid[i][j] = 0;

        for(auto dir : directions)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            fish += dfs(i_, j_, m, n, grid);
        }
        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int fish = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] > 0){
                    fish = max(fish, dfs(i, j, m, n, grid));
                }
            }
        }
        return fish;
    }
};