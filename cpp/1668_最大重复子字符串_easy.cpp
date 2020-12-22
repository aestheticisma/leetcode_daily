class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int res = 0;
        for(int i=0; i<sequence.length(); i++){
            int index = 0;
            int ans = 0;
            if(sequence[i]==word[index]){
                int j=i;
                while(index<word.length() && j<sequence.length()){
                    if(sequence[j]==word[index]){
                        j++;
                        index++;
                    }
                    else
                        break;
                    if(index==word.length()){
                        ans++;
                        index = 0;
                    }
                }
                res = max(res, ans);
            }
        }
        return res;
    }
};