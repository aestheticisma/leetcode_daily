# 位运算

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        if not matrix:
            return
        r, c = 0, 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    bitsR, bitsC = 1 << i, 1 << j
                    if not (r & bitsR):
                        r += bitsR
                    if not (c & bitsC):
                        c += bitsC
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if r & (1<<i):
                    matrix[i][j] = 0
                    continue
                if c & (1<<j):
                    matrix[i][j] = 0
        return