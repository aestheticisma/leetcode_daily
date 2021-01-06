class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        vector<int> color(N, 0);
        int num = 0;
        for(int i=0; i<N; i++){
            if(color[i] == 0){
                num++;
                circleDFS(isConnected, color, i, -1);
            }
        }
        return num;
    }
    void circleDFS(vector<vector<int>> &isConnected, vector<int> &color, int v, int p){
        color[v] = 1;
        for(int i=0; i<isConnected.size(); i++){
            if(i==v || i==p)
                continue;
            if(isConnected[v][i] == 1 && color[i] == 0)
                circleDFS(isConnected, color, i, v);
        }
        color[v] = 2;
    }
};