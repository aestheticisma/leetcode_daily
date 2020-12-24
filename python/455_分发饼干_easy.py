class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g, s = sorted(g), sorted(s)
        i, j = 0, 0
        while i<len(g) and j<len(s):
            if s[j] >= g[i]:
                i, j = i+1, j+1
            else:
                j+=1
        return i