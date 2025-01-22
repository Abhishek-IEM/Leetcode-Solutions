class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> directions = {{0, 1},{0, -1},{1, 0}, {-1, 0}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();

        vector<vector<int>> height(m, vector<int> (n, -1));

        queue<P> q;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isWater[i][j] == 1)
                {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty())
        {
            int N = q.size();
            while(N--)
            {
                P curr = q.front();
                q.pop();

                int i = curr.first, j = curr.second;

                for(auto &dir : directions)
                {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && height[i_][j_] == -1)
                    {
                        height[i_][j_] = height[i][j] + 1;
                        q.push({i_, j_});
                    }
                }
            }
        }
        return height;
    }
};