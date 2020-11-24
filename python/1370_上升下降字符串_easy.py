class Solution:
    def sortString(self, s: str) -> str:
        if not s:
            return ''
        freq = {}
        for ch in s:
            if ch in freq:
                freq[ch] += 1
            else: freq[ch] = 1
        flag = -1
        ans = ''

        # chr将整形数变为字符, ord将字符变为整形数
        ch26 = [chr(ord('a')+i) for i in range(26)]
        while(flag!=len(ans)):
            flag = len(ans)
            for ch in ch26:
                if ch in freq and freq[ch] > 0:
                    ans += ch
                    freq[ch] -= 1
            for ch in ch26[::-1]:
                if ch in freq and freq[ch] > 0:
                    ans += ch
                    freq[ch] -= 1
        return ans