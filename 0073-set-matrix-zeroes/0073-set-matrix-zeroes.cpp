class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<pair<int, int>> p;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    p.push_back({i, j});
                }
            }
        }

        for (auto &pr : p)
        {
            int a = pr.first;
            int b = pr.second;

            for(int x = 0; x < m; x++) matrix[a][x] = 0;
            for(int y = 0; y < n; y++) matrix[y][b] = 0;
        }
    }
};