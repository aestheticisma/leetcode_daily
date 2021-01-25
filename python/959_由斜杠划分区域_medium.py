class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        n = len(grid)
        uf = UnionFind(4*n*n)
        for i in range(n):
            for j in range(n):
                idx = i*n+j
                if i<n-1:
                    uf.united(4*idx+2, 4*(idx+n))
                if j<n-1:
                    uf.united(4*idx+1, 4*(idx+1)+3)
                if grid[i][j] == '/':
                    uf.united(4*idx, 4*idx+3)
                    uf.united(4*idx+1, 4*idx+2)
                elif grid[i][j] == '\\':
                    uf.united(4*idx, 4*idx+1)
                    uf.united(4*idx+2, 4*idx+3)
                else:
                    uf.united(4*idx, 4*idx+1)
                    uf.united(4*idx+1, 4*idx+2)
                    uf.united(4*idx+2, 4*idx+3)
        return uf.setCount
class UnionFind():
    def __init__(self, n):
        self.n = n
        self.setCount = n
        self.parent = [i for i in range(n)]
        self.sz = [1 for i in range(n)]
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