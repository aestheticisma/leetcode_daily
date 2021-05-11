class Solution:
    def decode(self, encoded: List[int]) -> List[int]:
        n, total = len(encoded), 0
        ans = [0] * (n+1)
        for i in range(1, n+2):
            total ^= i
        for i in range(1, n, 2):
            ans[0] ^= encoded[i]
        ans[0] ^= total
        for i in range(1, n+1):
            ans[i] = ans[i-1] ^ encoded[i-1]
        return ans