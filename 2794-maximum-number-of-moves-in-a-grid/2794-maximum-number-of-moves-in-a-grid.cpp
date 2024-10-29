class Solution {
public:
    int m; //rows
    int n; //cols
    vector<int> directions = {-1, 0, 1};

    int DFS(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(dp[row][col] != -1) return dp[row][col];
        int moves = 0;
        for(int &dir : directions)
        {
            int newRow = row + dir;
            int newCol = col + 1;

            if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] > grid[row][col])
            {
                moves = max(moves, 1 + DFS(newRow, newCol, grid, dp));
            }
        }
        return dp[row][col] = moves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int result = 0;
        vector<vector<int>> dp(m, vector<int> (n ,-1));
        for(int i = 0; i < m; i++)
        {
            result = max(result, DFS(i, 0, grid, dp));
        }
        return result;
    }
};