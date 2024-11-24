class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int small = INT_MAX, countNeg = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0) countNeg++;
                small = min(small, abs(matrix[i][j]));
            }
        }
        if(countNeg % 2 == 0) return sum;
        return sum - 2 * small;
    }
};