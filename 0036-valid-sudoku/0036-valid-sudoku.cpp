class Solution {
public:
    bool satisfy(vector<vector<char>>& mat, int i, int j, char num) {
        for (int r = 0; r < 9; r++) {
            if (mat[i][r] == num || mat[r][j] == num) return false;
        }

        int sr = i - i % 3;
        int sc = j - j % 3;

        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (mat[sr + r][sc + c] == num) return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& mat) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (mat[i][j] != '.') {  
                    char num = mat[i][j];
                    mat[i][j] = '.'; 
                    if (!satisfy(mat, i, j, num)) return false;
                    mat[i][j] = num; 
                }
            }
        }
        return true;
    }
};