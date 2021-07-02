from collections import Counter
class Solution:
    def frequencySort(self, s: str) -> str:
        sList = []
        for ch, n in Counter(s).items():
            sList.append([ch, n])
        sList = sorted(sList, key=lambda x: -x[1])
        return ''.join(i*j for i, j in sList)