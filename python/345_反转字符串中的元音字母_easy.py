class Solution:
    def reverseVowels(self, s: str) -> str:
        def isvowel(ch):
            return ch in 'aeiouAEIOU'
        s = list(s)
        n = len(s)
        i, j = 0, n-1
        while i < j:
            while i<n and not isvowel(s[i]):
                i += 1
            while j>0 and not isvowel(s[j]):
                j -= 1
            if i < j:
                s[i], s[j] = s[j], s[i]
                i += 1
                j -= 1
        return ''.join(s)