class Solution {
public:

    void find(int row, int n, vector<string> &Board, vector<bool> &column, int &count, vector<bool> &leftDig, vector<bool> &RightDig)
    {
        if(row == n)
        {
            count++;
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
                find(row + 1, n, Board, column, count, leftDig, RightDig);
                column[j] = 0;
                Board[row][j] = '.';
                leftDig[n - 1 + j - row] = 0;
                RightDig[row + j] = 0;
            }
        }
    }

    int totalNQueens(int n) {
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
        int count = 0;
        find(0, n, Board, column, count, leftDig, RightDig);
        return count;
    }
};