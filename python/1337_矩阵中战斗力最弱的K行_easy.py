class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        m, n = len(mat), len(mat[0])
        data = collections.defaultdict(list)
        for i in range(m):
            tmp = mat[i]
            left, right = 0, n-1
            p = n
            while left <= right:
                mid = left + (right - left) // 2
                if tmp[mid] < 1:
                    p = mid
                    right = mid - 1
                else:
                    left = mid + 1
            data[p].append(i)
        ans = []
        for i in range(0, n+1):
            if k and data[i]:
                if k - len(data[i]) >= 0:
                    ans.extend(data[i])
                    k -= len(data[i])
                else:
                    ans.extend(data[i][:k])
                    k = 0
        return ans