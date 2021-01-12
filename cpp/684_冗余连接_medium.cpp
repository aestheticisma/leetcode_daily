class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> components(edges.size()+1);
        for(int i=1; i<edges.size(); i++)
            components[i] = i;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(find(components, u)!=find(components, v))
                Union(components, u, v);
            else
                return {u, v};
        }
        return {};
    
    }
    int find(vector<int> &components, int x){
        if(components[x]!=x)
            components[x] = find(components, components[x]);
        return components[x];
    }
    void Union(vector<int> &components, int u, int v){
        components[find(components, u)] = find(components, v);
    }
};