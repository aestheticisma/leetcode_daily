class Solution:
    def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
        status = copy.deepcopy(grid)
        row, col = len(grid), len(grid[0])
        uf = UnionFind(row*col+1)
        for (r, c) in hits:
            status[r][c] = 0
        for i in range(row):
            for j in range(col):
                if status[i][j] == 1:
                    if i == 0:
                        # uf.united(i*col+j, row*col)
                        uf.united(row*col, i*col+j)
                    if i>0 and status[i-1][j] == 1:
                        uf.united(i*col+j, (i-1)*col+j)
                    if j>0 and status[i][j-1] == 1:
                        uf.united(i*col+j, i*col+j-1)
        direction = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        ans = [0 for i in range(len(hits))]
        for i in range(len(hits)-1, -1, -1):
            r, c = hits[i][0], hits[i][1]
            if(grid[r][c] == 0):
                continue
            pre = uf.size[uf.find(row*col)]
            if(r == 0):
                uf.united(r*col+c, row*col)
            for (dr, dc) in direction:
                nr, nc = r + dr, c + dc
                if (nr>=0 and nr < row) and (nc >=0 and nc < col):
                    if status[nr][nc] == 1:
                        uf.united(r*col+c, nr*col+nc)
            cur = uf.size[uf.find(row*col)]
            ans[i] = max(0, cur-pre-1)
            status[r][c] = 1
        return ans

class UnionFind():
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.size = [1 for i in range(n)]
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def united(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return
        self.parent[x] = y
        self.size[y] += self.size[x]