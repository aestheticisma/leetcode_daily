class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = dict()
        setEqu = set()
        for i in range(len(equations)):
            a, b = equations[i]
            graph[(a, b)] = values[i]
            graph[(b, a)] = 1/values[i]
            setEqu.add(a)
            setEqu.add(b)
        listEqu = list(setEqu)
        for k in listEqu:
            for i in listEqu:
                for j in listEqu:
                    if (i, k) in graph and (k ,j) in graph:
                        graph[(i, j)] = graph[(i, k)]*graph[(k, j)]
        ans = []
        for (a, b) in queries:
            if (a, b) in graph:
                ans.append(graph[(a, b)])
            else:
                ans.append(-1)
        return ans