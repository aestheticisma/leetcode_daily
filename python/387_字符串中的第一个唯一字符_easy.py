class Solution:
    def firstUniqChar(self, s: str) -> int:
        strMap = collections.Counter(s)
        for index, ch in enumerate(s):
            if strMap[ch] == 1:
                return index
        return -1