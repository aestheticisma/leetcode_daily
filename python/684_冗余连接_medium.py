class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        N = len(edges)
        components = [i for i in range(N+1)]

        def find(x):
            if components[x] != x:
                components[x] = find(components[x])
            return components[x]
        def Union(u, v):
            components[find(u)] = find(v)
        
        for edge in edges:
            u, v = edge
            if find(u) != find(v):
                Union(u, v)
            else:
                return edge;
        return []
