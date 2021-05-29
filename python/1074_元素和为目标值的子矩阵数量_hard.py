class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        def subArrayFindK(array, k):
            cnt, pre, ans = Counter([0]), 0, 0
            for n in array:
                pre += n
                if pre-k in cnt:
                    ans += cnt[pre-k]
                cnt[pre] += 1
            return ans
        
        m, n = len(matrix), len(matrix[0])
        res = 0
        for i in range(m):
            data = [0] * n
            for j in range(i, m):
                for c in range(0, n):
                    data[c] += matrix[j][c]
                res += subArrayFindK(data, target)
        return res