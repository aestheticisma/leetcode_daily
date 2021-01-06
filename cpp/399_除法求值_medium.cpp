class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> tmp;
        vector<vector<double>> graph(40, vector<double>(40, 0));
        int index = 0;
        for(int i=0; i<equations.size(); i++){
            string a = equations[i][0];
            string b = equations[i][1];
            if(!tmp.count(a)) tmp[a] = index++;
            if(!tmp.count(b)) tmp[b] = index++;
            graph[tmp[a]][tmp[b]] = values[i];
            graph[tmp[b]][tmp[a]] = 1.0/values[i];
        }
        for(int k=0; k<index; k++)
            for(int i=0; i<index; i++)
                for(int j=0; j<index; j++)
                    if(graph[i][j]==0)
                        graph[i][j] = graph[i][k]*graph[k][j];
        vector<double> ans;
        for(int i=0; i<queries.size(); i++){
            string a = queries[i][0];
            string b = queries[i][1];
            if(!tmp.count(a) || !tmp.count(b))
                ans.push_back(-1);
            else{
                int _a = tmp[a];
                int _b = tmp[b];
                if(graph[_a][_b] == 0)
                    ans.push_back(-1);
                else
                    ans.push_back(graph[tmp[a]][tmp[b]]);
            }
        }
        return ans;
    }
};