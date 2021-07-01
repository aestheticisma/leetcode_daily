class Solution:
    def __init__(self):
        self.ways = 0
    def numWays(self, n: int, relation: List[List[int]], k: int) -> int:
        graph = collections.defaultdict(list)
        for r in relation:
            graph[r[0]].append(r[1])
        
        def dfs(index, step):
            if step == k:
                if index == n-1:
                    self.ways += 1
                return
            for to in graph[index]:
                dfs(to, step+1)
        
        dfs(0, 0)
        return self.ways

                    
