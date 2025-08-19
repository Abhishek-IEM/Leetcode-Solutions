class Solution {
public:
    vector<int> row = {-1, 1, 0, 0};
    vector<int> col = {0, 0, -1, 1};

    bool isValid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    bool isClosed = true;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 1; // mark visited

                    while (!q.empty()) {
                        auto [a, b] = q.front();
                        q.pop();

                        // if touches border, not closed
                        if (a == 0 || a == n-1 || b == 0 || b == m-1)
                            isClosed = false;

                        for (int k = 0; k < 4; k++) {
                            int new_a = a + row[k], new_b = b + col[k];
                            if (isValid(new_a, new_b, n, m) && grid[new_a][new_b] == 0) {
                                grid[new_a][new_b] = 1;
                                q.push({new_a, new_b});
                            }
                        }
                    }
                    if (isClosed) count++;
                }
            }
        }
        return count;
    }
};
