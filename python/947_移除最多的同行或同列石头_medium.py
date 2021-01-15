class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        nodeSet = set()
        def createGraph():
            graphX = collections.defaultdict(list)
            graphY = collections.defaultdict(list)
            for x, y in stones:
                graphX[x].append([x, y])
                graphY[y].append([x, y])
            return graphX, graphY 

        def dfs(node):
            if tuple(node) in nodeSet:
                return 
            nodeSet.add(tuple(node))
            for x in graphX[node[0]]:
                dfs(x)
            for y in graphY[node[1]]:
                dfs(y)

        graphX, graphY = createGraph()
        ans = 0
        for stone in stones:
            if tuple(stone) not in nodeSet:
                ans += 1
                dfs(stone)
        return len(stones)-ans