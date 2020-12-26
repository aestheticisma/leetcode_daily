class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        strMaps, strMapt = dict(), dict()
        for i in range(0, len(s)):
            x, y = s[i], t[i]
            if (x in strMaps and strMaps[x] != y) or (y in strMapt and strMapt[y] != x):
                return False
            strMaps[x] = y
            strMapt[y] = x
        return True