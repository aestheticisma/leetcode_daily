class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows, columns = [[0]*9 for i in range(9)], [[0]*9 for i in range(9)]
        subBoxs = [[[0]*9 for i in range(3)] for i in range(3)]

        for i in range(9):
            for j in range(9):
                ch = board[i][j]
                if ch != '.':
                    t = ord(ch) - ord('0') - 1
                    rows[i][t] += 1
                    columns[j][t] += 1
                    subBoxs[i//3][j//3][t] += 1
                    if rows[i][t] > 1 or columns[j][t] > 1 or subBoxs[i//3][j//3][t] > 1:
                        return False
        return True