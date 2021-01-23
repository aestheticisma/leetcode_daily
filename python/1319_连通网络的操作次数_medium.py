class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        uf = UnionFind(n)
        count = 0
        for (x, y) in connections:
            if uf.united(x, y):
                continue
            else:
                count += 1
        return uf.setCount-1 if count>=uf.setCount-1 else -1

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.setCount = n
        self.size = [1 for i in range(n)]
        self.parent = [i for i in range(n)]
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def united(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return False
        if self.size[x] < self.size[y]:
            x, y = y, x
        self.parent[y] = x
        self.size[x] += self.size[y]
        self.setCount -= 1
        return True