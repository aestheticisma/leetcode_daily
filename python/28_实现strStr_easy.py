class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        def KMP(p, q):
            next = [-1]
            m, n = len(p), len(q)
            i, j = 0, -1
            while (i < n-1):
                if j == -1 or q[i] == q[j]:
                    i += 1
                    j += 1
                    next.append(j)
                else:
                    j = next[j]
            i, j = 0, 0
            while (i<m and j<n):
                if j==-1 or p[i] == q[j]:
                    i += 1
                    j += 1
                else:
                    j = next[j]
            return i-j if j == n else -1
        if not len(needle):
            return 0
        return KMP(haystack, needle)
            