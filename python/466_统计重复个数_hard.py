class Solution:
    def getMaxRepetitions(self, s1: str, n1: int, s2: str, n2: int) -> int:
        hash_map = dict()
        s1cnt, s2cnt, index = 0, 0, 0
        while True:
            s1cnt += 1
            for ch in s1:
                if ch == s2[index]:
                    index += 1
                    if index == len(s2):
                        index, s2cnt = 0, s2cnt+1
            if s1cnt == n1:
                return s2cnt//n2
            if index in hash_map:
                pre_s1cnt, pre_s2cnt = hash_map[index][0], hash_map[index][1]
                inloop = (s1cnt-pre_s1cnt, s2cnt-pre_s2cnt)
                break
            else: hash_map[index] = (s1cnt, s2cnt)
        
        ans = pre_s2cnt + (n1-pre_s1cnt)//inloop[0] * inloop[1]
        rest_cnt = (n1-pre_s1cnt) % inloop[0]
        for i in range(rest_cnt):
            for ch in s1:
                if ch == s2[index]:
                    index += 1
                    if index == len(s2):
                        index, ans = 0, ans+1
        return ans // n2