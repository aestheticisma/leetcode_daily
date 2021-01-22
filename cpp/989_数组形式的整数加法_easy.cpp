class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n = A.size();
        vector<int> ans;
        for(int i=n-1; i>=0; i--){
            A[i] += K%10;
            K /= 10;
            if(A[i]>=10){
                A[i] -= 10;
                K++;
            }
            ans.push_back(A[i]);
        }
        for(; K>0; K/=10)
            ans.push_back(K%10);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};