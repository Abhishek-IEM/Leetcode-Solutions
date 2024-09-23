class Solution {
public:

    void find(int row, int n, vector<vector<string>> &ans, vector<string> &Board, vector<bool> &column, vector<bool> &leftDig, vector<bool> &RightDig)
    {
        if(row == n)
        {
            ans.push_back(Board);
            return;
        }
        for(int j = 0; j < n; j++)
        {
            if(column[j] == 0 && leftDig[n - 1 + j - row] == 0 && RightDig[row + j] == 0)
            {
                column[j] = 1;
                Board[row][j] = 'Q';
                leftDig[n - 1 + j - row] = 1;
                RightDig[row + j] = 1;
                find(row + 1, n, ans, Board, column, leftDig, RightDig);
                column[j] = 0;
                Board[row][j] = '.';
                leftDig[n - 1 + j - row] = 0;
                RightDig[row + j] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> Board(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                Board[i].push_back('.');
            }
        }
        vector<bool> column(n, 0);
        vector<bool> leftDig(2 * n - 1, 0);
        vector<bool> RightDig(2 * n - 1, 0);
        find(0, n, ans, Board, column, leftDig, RightDig);
        return ans;
    }
};