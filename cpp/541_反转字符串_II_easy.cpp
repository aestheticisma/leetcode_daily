class Solution {
public:
    string reverseStr(string s, int k) {
        int N = s.length();
        for(int i=0; i<N; i+=2*k){
            int j = i;
            int t = min(N-1, j+k-1);
            while(j<t){
                char temp = s[j];
                s[j++] = s[t];
                s[t--] = temp;
            }
        } 
        return s;
    }
    
};