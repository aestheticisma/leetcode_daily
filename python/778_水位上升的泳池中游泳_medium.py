class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        rows, columns = len(grid), len(grid[0])
        seen = set()
        q = [(grid[0][0], 0, 0)]
        directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        ans = 0
        while q:
            t, x, y = heapq.heappop(q)
            idx = x*columns+y
            if idx in seen:
                continue
            ans = max(ans, t)
            if x == rows-1 and y == columns-1:
                break
            seen.add(idx)
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0<=nx<rows and 0<=ny<columns and nx*columns+ny not in seen:
                    heapq.heappush(q, (grid[nx][ny], nx, ny))
        return ans
            