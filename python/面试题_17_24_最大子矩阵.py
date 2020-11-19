# 降维 动态规划：连续最大子序列和
class Solution:
    def getMaxMatrix(self, matrix: List[List[int]]) -> List[int]:
        N = len(matrix)
        M = len(matrix[0])
        ans = float("-inf")
        r1, c1 = 0, 0
        dp, dp_i = [0]*M, 0
        for i in range(N):
            dp = [0]*M
            for j in range(i, N):
                dp_i = 0
                for k in range(0, M):
                    dp[k] += matrix[j][k]
                    if dp_i>0:
                        dp_i+=dp[k]
                    else:
                        dp_i=dp[k]
                        r1, c1 = i, k
                    if dp_i > ans:
                        ans = dp_i
                        ans_pos = [r1, c1, j, k]
        return ans_pos