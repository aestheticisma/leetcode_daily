const int MouseWin = 1;
const int CatWin = 2;
const int Draw = 0;
const int MAXNUM = 51;

class Solution {
private:
    int n;
    vector<vector<int>> graph;
    int dp[MAXNUM][MAXNUM][MAXNUM*2];

public:
    int catMouseGame(vector<vector<int>>& graph) {
        this->n = graph.size();
        this->graph = graph;
        memset(dp, -1, sizeof(dp));
        return getResult(1, 2, 0);
    }
    int getResult(int mouse, int cat, int turns) {
        if (turns == n * 2) return Draw;
        if (dp[mouse][cat][turns] < 0) {
            if (mouse == 0) dp[mouse][cat][turns] = MouseWin;
            else if (mouse == cat) dp[mouse][cat][turns] = CatWin;
            else getNextResult(mouse, cat, turns);
        }
        return dp[mouse][cat][turns];
    }
    void getNextResult(int mouse, int cat, int turns) {
        int curMove = turns % 2 == 0 ? mouse : cat;
        int defaultResult = curMove == mouse ? CatWin : MouseWin;
        int result = defaultResult;
        for (const int next : graph[curMove]) {
            if (curMove == cat && next == 0) continue;
            int mouseNext = curMove == mouse ? next : mouse;
            int catNext = curMove == cat ? next : cat;
            int nextResult = getResult(mouseNext, catNext, turns+1);
            if (nextResult != defaultResult) {
                result = nextResult;
                if (result != Draw) {
                    break;
                }
            }
        }
        dp[mouse][cat][turns] = result;
    }
};