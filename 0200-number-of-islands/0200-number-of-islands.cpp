class Solution {
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j, int n, int m)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '0') continue;
                else if(grid[i][j] == '1')
                {
                    count++;
                    grid[i][j] = 0;
                    queue<pair<int, int> > q;
                    q.push({i, j});
    
                    while(!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int k = 0; k < 4; k++)
                        {
                            if(valid(x + row[k], y + col[k], n, m) && grid[x + row[k]][y + col[k]] == '1')
                            {
                                grid[x + row[k]][y + col[k]] = 0;
                                q.push({x + row[k], y + col[k]});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};