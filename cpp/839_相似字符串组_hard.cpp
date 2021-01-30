class UnionFind {
private:
    vector<int> parent;
    vector<int> sz;
    int setCount;
public:
    UnionFind (int n): parent(n), sz(n, 1), setCount(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find (int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool united (int x, int y) {
        x = find(x);
        y = find(y);
        if (x==y)
            return false;
        parent[y] = x;
        sz[x] += sz[y];
        setCount--;
        return true;
    }
    int get_setCount() {
        return setCount;
    }

};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        auto uf = UnionFind(n);
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++) 
                if (equal(strs[i], strs[j]))
                    uf.united(i ,j);
        return uf.get_setCount();
    }
    bool equal(string a, string b) {
        int n = a.length();
        int count = 0;
        for(int i=0; i<n; i++) {
            if (a[i] != b[i])
                count++;
            if (count > 2)
                return false;
        }
        return true;
    }
};