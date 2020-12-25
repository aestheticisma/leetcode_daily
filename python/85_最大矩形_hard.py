class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        rows = len(matrix)
        cols = len(matrix[0])
        dp = [[[0, 0, 0] for i in range(cols)] for i in range(rows)]
        ans = 0
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == '1':
                    if i == 0 and j == 0:
                        dp[i][j] = [1, 1, 1]
                    elif i == 0:
                        dp[i][j][0], dp[i][j][1], dp[i][j][2] = dp[i][j-1][0]+1, 1, dp[i][j-1][2]+1
                    elif j == 0:
                        dp[i][j][0], dp[i][j][1], dp[i][j][2] = 1, dp[i-1][j][1]+1, dp[i-1][j][2]+1
                    else:
                        dp[i][j][0], dp[i][j][1] = dp[i][j-1][0]+1, dp[i-1][j][1]+1
                        _cols_min = dp[i][j][0]
                        _rows = dp[i][j][1]
                        # area = 0
                        for k in range(_rows):
                            _cols_min = min(_cols_min, dp[i-k][j][0])
                            dp[i][j][2] = max(dp[i][j][2], _cols_min*(k+1))
                    ans = max(ans, dp[i][j][2])
        return ans