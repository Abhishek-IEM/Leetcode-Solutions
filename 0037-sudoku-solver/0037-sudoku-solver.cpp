class Solution {
public:
    bool check(int num, vector<vector<char>>& board, int i, int j)
    {
        char c = '0' + num;
        //check at same row
        for(int col = 0; col < 9; col++)
        {
            if(board[i][col] == c) return 0;
        }
        //check at same col
        for(int row = 0; row < 9; row++)
        {
            if(board[row][j] == c) return 0;
        }
        //check at same box
        int row = i / 3 * 3, col = j / 3 * 3;
        for(int a = row; a < row + 3; a++)
        for(int b = col; b < col + 3; b++)
        {
            if(board[a][b] == c) return 0;
        }
        return 1;
    }

    bool find(int i, int j, vector<vector<char>>& board)
    {
        if(i == 9) return 1;
        if(j == 9) return find(i + 1, 0, board);
        if(board[i][j] != '.') return find(i, j + 1, board);

        for(int  num = 1; num <= 9; num++)
        {
            if(check(num, board, i, j))
            {
                board[i][j] = '0' + num;
                if(find(i, j + 1, board)) return 1;
                board[i][j] = '.';
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        find(0, 0, board);
    }
};