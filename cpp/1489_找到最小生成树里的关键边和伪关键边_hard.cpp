class UnionFind{
public:
    vector<int> parent;
    int n;
    vector<int> size;
    int setCount;
public:
    UnionFind(int _n): n(_n), size(_n, 1), setCount(n), parent(_n){
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        return parent[x] == x ? x : parent[x]=find(parent[x]);
    }
    bool united(int x, int y){
        int _x = find(x);
        int _y = find(y);
        if(_x == _y)
            return false;
        if(size[_x] < size[_y])
            swap(_x, _y);
        size[_x] += size[_y];
        parent[_y] = _x;
        setCount--;
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for(int i=0; i<m; i++)
            edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [](const auto &x, const auto &y){
            return x[2]<y[2];
        });

        UnionFind uf0(n);
        int value = 0;
        for(auto edge : edges)
            if(uf0.united(edge[0], edge[1]))
                value += edge[2];
        
        vector<vector<int>> ans(2);
        for(int i=0; i<m; i++){
            UnionFind uf(n);
            int v = 0;
            for(int j=0; j<m; j++)
                if(j!=i && uf.united(edges[j][0], edges[j][1]))
                    v += edges[j][2];
            if(uf.setCount != 1 || (uf.setCount==1 && v>value)){
                ans[0].push_back(edges[i][3]);
                continue;
            }

            uf = UnionFind(n);
            uf.united(edges[i][0], edges[i][1]);
            v = edges[i][2];
            for(int j=0; j<m; j++)
                if(j!=i && uf.united(edges[j][0], edges[j][1]))
                    v += edges[j][2];
            if(uf.setCount==1 && v==value)
                ans[1].push_back(edges[i][3]);
        }
        return ans;


    }
};