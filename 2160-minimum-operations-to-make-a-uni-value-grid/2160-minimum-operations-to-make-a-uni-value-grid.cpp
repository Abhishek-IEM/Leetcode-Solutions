class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();
        vector<int> vec;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                vec.push_back(grid[i][j]);
            }
        }

        int l = vec.size();

        nth_element(begin(vec), begin(vec) + l/2, end(vec)); //O(L)

        int result = 0, target = vec[l / 2];

        for(int &num : vec)
        {
            if(num % x != target % x) return -1;
            result += abs(target - num) / x;
        } 

        return result;
    }
};