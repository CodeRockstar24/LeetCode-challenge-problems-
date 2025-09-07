class Solution {
    array<bitset<9>,9> row_contains, col_contains, cell_contains;

    inline size_t get_cell(size_t row, size_t col) {
        return (row / 3) * 3 + (col / 3);
    }

    bool solve(vector<vector<char>>& board, size_t row, size_t col) {
        if (row == 9) return true; // solved
        if (col == 9) return solve(board, row+1, 0); // next row

        if (board[row][col] != '.') return solve(board, row, col+1);

        size_t cell = get_cell(row, col);

        for (char d = '1'; d <= '9'; ++d) {
            size_t idx = d - '1';
            if (!row_contains[row][idx] && !col_contains[col][idx] && !cell_contains[cell][idx]) {
                // place digit
                board[row][col] = d;
                row_contains[row].set(idx);
                col_contains[col].set(idx);
                cell_contains[cell].set(idx);

                if (solve(board, row, col+1)) return true;

                // backtrack
                board[row][col] = '.';
                row_contains[row].reset(idx);
                col_contains[col].reset(idx);
                cell_contains[cell].reset(idx);
            }
        }
        return false; // no valid number found
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        // initialize bitsets
        for (size_t r=0;r<9;++r){
            for (size_t c=0;c<9;++c){
                char d = board[r][c];
                if (d != '.') {
                    size_t idx = d-'1';
                    row_contains[r].set(idx);
                    col_contains[c].set(idx);
                    cell_contains[get_cell(r,c)].set(idx);
                }
            }
        }

        solve(board, 0, 0);
    }
};
