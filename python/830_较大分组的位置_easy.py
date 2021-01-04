class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        N = len(s)
        if N < 3:
            return []
        ans = []
        i = 0
        while i + 2 < N:
            if s[i] == s[i+1] and s[i+1] == s[i+2]:
                start = i
                i += 2
                while(i+1<N and s[i]==s[i+1]):
                    i += 1
                end = i
                ans.append([start, end])
            i += 1
        return ans