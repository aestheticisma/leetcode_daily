class UnionFind {
private:
    vector<int> parent;
    vector<int> sz;
    int setCount;
public:
    UnionFind(int n): setCount(n), parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool united(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        parent[y] = x;
        sz[x] += sz[y];
        setCount--;
        return true;
    }
    int size(int x) {
        return sz[find(x)];
    }
    int getSetCount() {
        return setCount;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        auto ufa = UnionFind(n), ufb = UnionFind(n);
        int res = 0;
        for (int i=0; i<edges.size(); i++){
            edges[i][1]--;
            edges[i][2]--;
        }
        for (auto &edge : edges) {
            if (edge[0] == 3) {
                if (!ufa.united(edge[1], edge[2]))
                    res++;
                else
                    ufb.united(edge[1], edge[2]);
            }
        }
        for (auto& edge: edges) {
            if (edge[0] == 1) {
                if (!ufa.united(edge[1], edge[2]))
                    res++;
            }
            else if (edge[0] == 2) {
                if (!ufb.united(edge[1], edge[2]))
                    res++;
            }
        }
        if (ufa.getSetCount() != 1 || ufb.getSetCount() != 1)
            return -1;
        return res;
    }
};