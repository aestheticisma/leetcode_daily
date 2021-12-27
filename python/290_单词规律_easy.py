class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        strMap = dict()
        strList = s.split()
        if len(pattern) != len(strList):
            return False
        for index, ch in enumerate(pattern):
            if ch not in strMap:
                if strList[index] in strMap.values():
                    return False
                strMap[ch] = strList[index]
            else:
                if strList[index] != strMap[ch]:
                    return False
        return True