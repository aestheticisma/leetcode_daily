class UnionFind{
private:
    vector<int> parent;
    vector<int> sz;
    int setCount;
public:
    UnionFind(int n): parent(n), sz(n, 1), setCount(n){
        iota(parent.begin(), parent.end(), 0);
    } 
    int find(int x){
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool united(int x, int y){
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        parent[y] = x;
        sz[x] += sz[y];
        setCount--;
        return true;
    }
    int size(int x){
        return sz[find(x)];
    }
    int get_setCount(){
        return setCount;
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        auto uf = UnionFind(4*n*n);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                int idx = i*n+j;
                if (i<n-1)
                    uf.united(4*idx+2, 4*(idx+n));
                if (j<n-1)
                    uf.united(4*idx+1, 4*(idx+1)+3);
                if (grid[i][j] == '/'){
                    uf.united(4*idx, 4*idx+3);
                    uf.united(4*idx+1, 4*idx+2);
                }
                else if (grid[i][j] == '\\'){
                    uf.united(4*idx, 4*idx+1);
                    uf.united(4*idx+2, 4*idx+3);
                }
                else {
                    uf.united(4*idx, 4*idx+1);
                    uf.united(4*idx+1, 4*idx+2);
                    uf.united(4*idx+2, 4*idx+3);
                }
            }
        return uf.get_setCount();
    }
};