class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9];
        int columns[9][9];
        int subBoxs[3][3][9];

        memset(rows, 0, sizeof(rows));
        memset(columns, 0, sizeof(columns));
        memset(subBoxs, 0, sizeof(subBoxs));

        for (int i=0; i<9; i++) {
            for (int j = 0; j<9; j++) {
                auto ch = board[i][j];
                if (ch != '.'){
                    int t = ch - '0' - 1;
                    rows[i][t]++;
                    columns[j][t]++;
                    subBoxs[i/3][j/3][t]++;
                    if (rows[i][t] > 1 || columns[j][t] > 1 || subBoxs[i/3][j/3][t] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};