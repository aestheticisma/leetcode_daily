class Solution {
public:
    string reorganizeString(string S) {
        int length = S.length();
        if(length<2)
            return S;
        int maxCount = 0;
        vector<int> chCount(26, 0);
        for(int i=0; i<length; i++){
            chCount[S[i]-'a'] += 1;
            maxCount = max(maxCount, chCount[S[i]-'a']);
        }
        if(maxCount>(length+1)/2)
            return "";
        string temp(length, ' ');
        int evenPos = 0, oddPos = 1;
        int halfLength = length/2;
        for(int i=0; i<26; i++){
            char ch = (char)('a'+i);
            while(chCount[i] && chCount[i]<=halfLength && oddPos<length){
                temp[oddPos] = ch;
                oddPos += 2;
                chCount[i]--;
            }
            while(chCount[i]){
                temp[evenPos] = ch;
                evenPos += 2;
                chCount[i]--;
            }
        }
        return temp;
    }
};