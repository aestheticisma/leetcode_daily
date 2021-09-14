class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        ans = ""
        for t in dictionary:
            i, j = 0, 0
            while i < len(t) and j < len(s):
                if t[i] == s[j]:
                    i += 1
                j += 1
            if i == len(t):
                if len(t) == len(ans):
                    ans = t if t < ans else ans
                else:
                    ans = t if len(t) > len(ans) else ans
        return ans