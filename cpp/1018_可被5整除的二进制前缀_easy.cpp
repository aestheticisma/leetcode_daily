class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int N = A.size();
        vector<bool> res;
        for(int i=0; i<N; i++){
            if(i==0)
                res.push_back(A[0]%5==0 ? true : false);
            else{
                int mod = (2*(A[i-1]%5)%5+A[i])%5;
                if(mod == 0)
                    res.push_back(true);
                else
                    res.push_back(false);
                A[i] = mod;
            }
        }
        return res;
    }
};