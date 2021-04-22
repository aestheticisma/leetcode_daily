from sortedcontainers import SortedList
class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        ans = float("-inf")
        m, n = len(matrix), len(matrix[0])
        for i in range(0, m):
            d = [0]*n
            for j in range(i, m):
                for c in range(0, n):
                    d[c] += matrix[j][c]
                sumSet = SortedList([0])
                s = 0
                for v in d:
                    s += v
                    lb = sumSet.bisect_left(s - k)
                    if lb != len(sumSet):
                        ans = max(ans, s - sumSet[lb])
                    sumSet.add(s)
        return ans