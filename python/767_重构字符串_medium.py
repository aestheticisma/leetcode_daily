class Solution:
    def reorganizeString(self, S: str) -> str:
        length = len(S)
        if length<2:
            return S
        chCount = [0 for i in range(26)]
        maxCount = 0
        for ch in S:
            chCount[ord(ch)-ord('a')] += 1
            maxCount = max(maxCount, chCount[ord(ch)-ord('a')])
        if maxCount > (length+1)//2:
            return ""
        evenPos, oddPos = 0, 1
        halfCount = length//2
        ans = [' ' for i in range(length)]
        for i in range(26):
            ch = chr(ord('a')+i)
            while(chCount[i] and chCount[i] <= halfCount and oddPos < length):
                ans[oddPos] = ch
                oddPos += 2
                chCount[i] -= 1
            while(chCount[i]):
                ans[evenPos] = ch
                evenPos += 2
                chCount[i] -= 1
        return ''.join(ans)