typedef pair<int, int> pii;
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        int ans = 0, i = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        while (i < n) {
            while (!pq.empty() && pq.top().first <= i) pq.pop();
            pii cur = make_pair(i + days[i], apples[i]);
            if (cur.second > 0) pq.push(cur);
            if (!pq.empty()) {
                pii cur = pq.top(); pq.pop();
                --cur.second;
                ++ans;
                if (cur.second > 0) pq.push(cur);
            }
            ++i;
        }
        while (!pq.empty()) {
            while (!pq.empty() && pq.top().first <= i) pq.pop();
            if (pq.empty()) break;
            pii cur = pq.top(); pq.pop();
            int num = min(cur.first - i, cur.second);
            ans += num;
            i += num;
        }
        return ans;
    }
};