class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        n, m = len(arr), len(queries)
        mem, ans = [0] * (n+1), list()
        for i in range(1, n+1):
            mem[i] = arr[i-1] ^ mem[i-1]
        for i in range(m):
            ans.append(mem[queries[i][0]] ^ mem[queries[i][1] + 1])
        return ans
