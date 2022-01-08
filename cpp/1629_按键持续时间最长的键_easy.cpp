class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        int time = releaseTimes[0];
        char key = keysPressed[0];
        for (int i = 1; i < n; ++i) {
            int cur_time = releaseTimes[i] - releaseTimes[i-1];
            char cur_key = keysPressed[i];
            if (cur_time > time || (cur_time == time && cur_key > key)) {
                time = cur_time;
                key = cur_key;
            }
        }
        return key;
    }
};