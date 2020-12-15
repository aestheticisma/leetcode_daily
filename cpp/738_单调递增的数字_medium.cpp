class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if(N<10)
            return N;
        string temp = to_string(N);
        for(int i=1; i<temp.length(); i++)
            if(temp[i]<temp[i-1]){
                int j = i-1;
                while(j>0 && temp[j]==temp[j-1]) j--;
                temp[j] -= 1;
                while(++j<temp.length()) temp[j] = '9';
            }
        return stoi(temp);
    }
};