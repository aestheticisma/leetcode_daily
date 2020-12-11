class Solution {
public:
    string predictPartyVictory(string senate) {
        int N = senate.length();
        queue<int> radiant, dire;
        for(int i=0; i<N; i++)
            if(senate[i]=='R')
                radiant.push(i);
            else
                dire.push(i);
        while(!radiant.empty() && !dire.empty()){
            if(radiant.front() < dire.front())
                radiant.push(radiant.front()+N);
            else
                dire.push(dire.front()+N);
            radiant.pop();
            dire.pop();
        }
        return radiant.empty() ? "Dire": "Radiant";
    }
};