class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int minRow = n, maxRow = -1, minCol = m, maxCol = -1;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1){
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);

                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                }
            }
        }

        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};