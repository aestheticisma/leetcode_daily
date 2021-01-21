class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        m = len(edges)
        for i, edge in enumerate(edges):
            edge.append(i)
        edges.sort(key = lambda x: x[2])
        uf0 = UnionFind(n)
        value = 0
        for i in range(m):
            if uf0.union(edges[i][0], edges[i][1]):
                value += edges[i][2]
        
        ans = [list(), list()]
        for i in range(m):
            uf1 = UnionFind(n)
            v = 0
            for j in range(m):
                if j!=i and uf1.union(edges[j][0], edges[j][1]):
                    v += edges[j][2]
            if uf1.setCount != 1 or (uf1.setCount == 1 and v > value):
                ans[0].append(edges[i][3])
                continue

            uf1 = UnionFind(n)
            uf1.union(edges[i][0], edges[i][1])
            v = edges[i][2]
            for j in range(m):
                if j!=i and uf1.union(edges[j][0], edges[j][1]):
                    v += edges[j][2]
            if v == value:
                ans[1].append(edges[i][3])
        return ans

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.size = [1 for i in range(n)]
        self.setCount = n
        self.parent = [i for i in range(n)]
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def union(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return False
        if self.size[x] < self.size[y]:
            x, y = y, x
        self.parent[y] = x
        self.size[x] += self.size[y]
        self.setCount -= 1
        return True