class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        ufa, ufb = UnionFind(n), UnionFind(n)
        res = 0
        for edge in edges:
            edge[1] -= 1
            edge[2] -= 1
        for t, v, u in edges:
            if t == 3:
                if not ufa.united(v, u):
                    res += 1
                else:
                    ufb.united(v, u)
        for t, v, u in edges:
            if t == 1:
                if not ufa.united(v, u):
                    res += 1
            elif t == 2:
                if not ufb.united(v, u):
                    res += 1
        if ufa.setCount != 1 or ufb.setCount != 1:
            return -1
        return res

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parent = [i for i in range(n)]
        self.sz = [1]*n
        self.setCount = n
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def united(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return False
        self.parent[y] = x
        self.sz[x] += self.sz[y]
        self.setCount -= 1
        return True
    def size(self, x):
        return self.sz[self.find(x)]