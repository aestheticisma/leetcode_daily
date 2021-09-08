class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        int cur = 0;
        vector<pair<int, int>> data;
        priority_queue<int> pq;
        for (int i=0; i<n; i++)
            data.push_back({capital[i], profits[i]});
        sort(data.begin(), data.end());
        for (int i=0; i<k; i++) {
            while (cur < n && data[cur].first <= w)
                pq.push(data[cur++].second);
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
            else
                break;
        }
        return w;
    }
};