class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        N = len(matrix[0])
        tmp = []
        for i in range(N):
            tmp.append(matrix[i][:])
        for i in range(N):
            for j in range(N):
                matrix[j][N-i-1] = tmp[i][j]
        return matrix