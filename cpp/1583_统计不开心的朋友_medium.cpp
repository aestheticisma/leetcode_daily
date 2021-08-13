class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> sequence(n, vector<int>(n));
        for (int i=0; i<n; i++)
            for (int j=0; j<n-1; j++)
                sequence[i][preferences[i][j]] = j;
        vector<int> match(n);
        for (int i=0; i<pairs.size(); i++) {
            int person0 = pairs[i][0], person1 = pairs[i][1];
            match[person0] = person1;
            match[person1] = person0;
        }
        int ans = 0;
        for (int x=0; x<n; x++) {
            int y = match[x];
            int index = sequence[x][y];
            for (int i=0; i<index; i++) {
                int u = preferences[x][i];
                int v = match[u];
                if (sequence[u][x] < sequence[u][v]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};