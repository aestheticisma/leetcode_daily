#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        if (pairs.empty() || pairs[0].empty()) return 0;
        unordered_map<int, unordered_set<int>> adj;
        for (const auto &p : pairs) {
            adj[p[0]].emplace(p[1]);
            adj[p[1]].emplace(p[0]);
        }
        int root = -1;
        for (const auto &[key, val] : adj) {
            if (val.size() == adj.size()-1) {
                root = key;
                break;
            }
        }
        if (root == -1) return 0;
        int res = 1;
        for (const auto &[node, neibor] : adj) {
            if (node == root) continue;
            int curNeiborSize = neibor.size();
            int parent = -1;
            int parentNeiborSize = INT_MAX;
            for (const int &ne : neibor) {
                if (adj[ne].size() < parentNeiborSize && adj[ne].size() >= curNeiborSize) {
                    parent = ne;
                    parentNeiborSize = adj[ne].size();
                }
            }
            if (parent == -1) return 0;
            for (const int &ne : neibor) {
                if (ne == parent) continue;
                if (!adj[parent].count(ne))
                    return 0;
            }
            if (parentNeiborSize == curNeiborSize)
                res = 2;
        }
        return res;
    }
};