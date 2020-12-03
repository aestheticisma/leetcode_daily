class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<int> temp(n, 1);
        for(int i=2; i<n; i++)
            if(temp[i]){
                ans ++;
                if((long long )i*i<n)
                    for(int j=i*i; j<n; j+=i)
                        temp[j] = 0;
            }
        return ans;
    }
};