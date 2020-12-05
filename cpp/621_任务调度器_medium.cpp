class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxCount = 0;
        int N = tasks.size();
        
        unordered_map<char, int> tasks_map;
        for(char task : tasks){
            tasks_map[task]++;
            maxCount = max(maxCount, tasks_map[task]);
        }
        int maxNum = 0;
        for(unordered_map<char, int> ::iterator iter=tasks_map.begin(); iter!=tasks_map.end(); iter++)
            if(iter->second == maxCount)
                maxNum++;
        return max( (maxCount-1) * (n+1) + maxNum, N );

    }
};