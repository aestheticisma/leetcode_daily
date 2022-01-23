struct cmp_less {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    }
};
struct cmp_greater {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};
class StockPrice {
private:
    unordered_map<int, int> hashStock;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp_less> p;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp_greater> q;
    int timeseq;
public:
    StockPrice() {
        this->timeseq = 0;
    }
    
    void update(int timestamp, int price) {
        timeseq = max(timeseq, timestamp);
        hashStock[timestamp] = price;
        p.emplace(timestamp, price);
        q.emplace(timestamp, price);
    }
    
    int current() {
        return hashStock[timeseq];
    }
    
    int maximum() {
        while (p.top().second != hashStock[p.top().first])
            p.pop();
        return p.top().second;
    }
    
    int minimum() {
        while (q.top().second != hashStock[q.top().first])
            q.pop();
        return q.top().second;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */