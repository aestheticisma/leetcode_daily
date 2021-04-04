class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> isSeen;
        int n = answers.size();
        int exAns = 0;
        for (auto an : answers) 
            if (an == 0)
                continue;
            else if (isSeen.find(an) == isSeen.end()) {
                isSeen[an] = an;
                exAns += an;
            }
            else {
                if (isSeen[an] > 0) {
                    isSeen[an]--;
                    exAns--;
                }
                else {
                    isSeen[an] = an;
                    exAns += an;
                }
            }
        return n + exAns;

    }
};