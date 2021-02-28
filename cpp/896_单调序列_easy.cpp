class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int inc = 0, des = 0;
        int N = A.size();
        for (int i=1; i<N; i++) {
            if (A[i] > A[i-1] && inc == 0)
                inc++;
            else if (A[i] < A[i-1] && des == 0)
                des++;
        }
        return inc & des ? false : true;
    }
};