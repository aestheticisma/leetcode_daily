class TimeMap {
private:
    unordered_map <string, vector<pair<int, string>>> data;

public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto &keyList = data[key];
        int left = 0, right = keyList.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (keyList[mid].first <= timestamp)
                left = mid + 1;
            else
                right = mid;
        }
        if (left > 0)
            return keyList[left-1].second;
        else
            return "";

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */