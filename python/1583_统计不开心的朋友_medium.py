class Solution:
    def unhappyFriends(self, n: int, preferences: List[List[int]], pairs: List[List[int]]) -> int:
        sequence, match = [[0] * n for _ in range(n)], [0]*n
        ans = 0
        for i in range(n):
            for j in range(n-1):
                sequence[i][preferences[i][j]] = j
        for pair in pairs:
            match[pair[0]] = pair[1]
            match[pair[1]] = pair[0]

        for x in range(n):
            y = match[x]
            index = sequence[x][y]
            for i in range(index):
                u = preferences[x][i]
                v = match[u]
                if sequence[u][x] < sequence[u][v]:
                    ans += 1
                    break
        return ans