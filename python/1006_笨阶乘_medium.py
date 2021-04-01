class Solution:
    def clumsy(self, N: int) -> int:
        if N <= 1:
            return 1 if N == 1 else 0
        operator = {
            0: mul,
            1: lambda x, y: int(x/y),
            2: add,
            3: sub
        }
        ans = N
        ansList = []
        for i in range(N, 1, -1):
            if (N-i) % 4 == 3:
                if not ansList:
                    ansList.append(ans)
                else:
                    ansList.append(-ans)
                ans = i-1
            elif (N-i) % 4 == 2:
                if not ansList:
                    ans += i-1
                else:
                    ansList[0] += i-1
            else:
                ans = operator[(N-i)%4](ans, i-1)
        if ansList:
            return sum(ansList)-ans
        else:
            return ans