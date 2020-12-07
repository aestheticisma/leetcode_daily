class Solution:
    def matrixScore(self, A: List[List[int]]) -> int:
        m, n = len(A), len(A[0])
        ans = m*(1<<(n-1))
        for j in range(1, n):
            nCount = 0
            for i in range(m):
                if A[i][0] == 1:
                    nCount += A[i][j]
                else:
                    nCount += (1-A[i][j])
            k = max(nCount, m-nCount)
            ans += k*(1<<(n-j-1))
        return ans