class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        N = len(isConnected)
        color = [0 for i in range(N)]
        def circleDFS(color, v, p):
            color[v] = 1
            for i in range(N):
                if i==v or i==p:
                    continue
                if isConnected[v][i] == 1 and color[i] == 0:
                    circleDFS(color, i, v)
            color[v] = 2

        num = 0
        for i in range(N):
            if color[i] == 0:
                num += 1
                circleDFS(color, i, -1)
        return num
    