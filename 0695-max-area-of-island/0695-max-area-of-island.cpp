class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int bfs(int i, int j, int m, int n, vector<vector<int>>& grid)
    {
        queue<pair<int, int>> q;
        q.push({i, j});

        int area = 1;
        grid[i][j] = 0;

        while(!q.empty())
        {
            i = q.front().first;
            j = q.front().second;

            q.pop();

            for(auto dir : directions)
            {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_ >= 0 && j_>= 0 && i_ < m && j_ < n && grid[i_][j_] == 1)
                {
                    q.push({i_, j_});
                    area ++;
                    grid[i_][j_] = 0;
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int area = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    area = max(area, bfs(i, j, m, n, grid));
                }
            }
        }
        return area;
    }
};