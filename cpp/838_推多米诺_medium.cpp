#include <vector>
#include <string>
#include <queue>

using namespace std;

// 双指针
class Solution1 {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        char left = 'L';
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && dominoes[j] == '.') ++j;
            char right = j < n ? dominoes[j] : 'R';
            if (left == right) {
                while (i < j) dominoes[i++] = right;
            }
            else if (left == 'R' && right == 'L') {
                int k = j - 1;
                while (i < k) {
                    dominoes[i++] = 'R';
                    dominoes[k--] = 'L';
                }
            }
            left = right;
            i = j + 1;
        }
        return dominoes;
    }
};

// BFS
class Solution2 {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<string> force(n);
        string res(n, '.');
        vector<int> time(n, -1);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] != '.') {
                time[i] = 0;
                q.push(i);
                force[i].push_back(dominoes[i]);
            }
        }
        while (!q.empty()) {
            int num = q.size();
            while (num--) {
                int cur = q.front(); q.pop();
                if (force[cur].size() == 1) {
                    char f = force[cur][0];
                    int t = time[cur];
                    res[cur] = f;
                    int next = f == 'L' ? cur - 1 : cur + 1;
                    if (next >= 0 && next < n) {
                        if (time[next] == -1) {
                            time[next] = t + 1;
                            q.push(next);
                            force[next].push_back(f);
                        }
                        else if (time[next] == t + 1)
                            force[next].push_back(f);
                    }
                }
            }
        }
        return res;
    }
};