class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        def reverse(s):
            # s = list(s)
            N = len(s)
            for i in range(0, (N+1)//2):
                s[i], s[N-i-1] = s[N-i-1], s[i]
            return s
        s = list(s)
        N = len(s)
        for i in range(0, N, 2*k):
            s[i:i+k] = reverse(s[i:i+k])
        return ''.join(s)