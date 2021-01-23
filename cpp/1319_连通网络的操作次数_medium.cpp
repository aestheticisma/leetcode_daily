class UnionFind{
public:
    vector<int> parent;
    vector<int> size;
    int setCount;
    int n;
public:
    UnionFind(int _n): n(_n), setCount(_n), parent(_n), size(_n, 0){
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        return parent[x]==x ? x : parent[x]=find(parent[x]);
    }
    bool united(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y)
            return false;
        if(size[x]<size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        setCount--;
        return true;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind uf = UnionFind(n);
        int count = 0;
        for(auto v : connections){
            int x = v[0], y = v[1];
            if(uf.united(x, y))
                continue;
            else
                count++;
        }
        return count>=uf.setCount-1 ? uf.setCount-1 : -1;
    }
};