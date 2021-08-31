class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        for x, y in zip_longest(version1.split('.'), version2.split('.'), fillvalue=0):
            x = int(x)
            y = int(y)
            if x != y:
                return 1 if x > y else -1
        return 0