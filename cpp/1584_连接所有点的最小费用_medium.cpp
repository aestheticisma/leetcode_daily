class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ans = 0;
        pq.push({0, 0});
        vector<bool> visit(N, false);
        while(!pq.empty() && N>0){
            auto [d, p1] = pq.top();
            pq.pop();
            if(visit[p1])
                continue;
            visit[p1] = true;
            N--;
            ans += d;
            for(int p2=0; p2<points.size(); p2++){
                if(visit[p2])
                    continue;
                int distance = abs(points[p2][0]-points[p1][0])+abs(points[p2][1]-points[p1][1]);
                pq.push({distance, p2});
            }
        }
        return ans;
    }
};