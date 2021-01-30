class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        def equal(strx, stry):
            count = 0
            for i in range(len(strx)):
                if strx[i] != stry[i]:
                    count += 1
                if count > 2:
                    return False
            return True   
        n = len(strs)
        uf = UnionFind(n)
        for i in range(n):
            for j in range(i+1, n):
                if equal(strs[i], strs[j]):
                    uf.united(i, j)
        return uf.get_setCount()

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parent = [i for i in range(n)]
        self.sz = [1 for i in range(n)]
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
    def get_setCount(self):
        return self.setCount