class TopVotedCandidate {
private:
    vector<int> hash;
    vector<int> _times;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> m;
        hash.resize(5000, 0);
        _times.resize(times.size());
        _times = times;
        int maxium = 0;
        for (int i = 0; i < persons.size(); ++i) {
            ++m[persons[i]];
            if (maxium <= m[persons[i]]) {
                maxium = m[persons[i]];
                hash[i] = persons[i];
            }
            else hash[i] = hash[i-1];
        }
    }
    
    int q(int t) {
        return hash[binarySearch(t)];
    }
    int binarySearch(int t) {
        int left = 0, right = _times.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (_times[mid] <= t)
                left = mid + 1;
            else
                right = mid;
        }
        return _times[left] <= t ? left : left-1;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */