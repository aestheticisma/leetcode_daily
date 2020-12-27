class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
       int N = prices.size();
       if(!N) return 0;
       k = min(k, N/2);
       vector<int> buy(k+1, 0);
       vector<int> sell(k+1, 0);
       buy[0] = -prices[0];
       for(int i=1; i<k+1; i++){
           buy[i] = INT_MIN;
       } 
       for(int i=1; i<N; i++){
           buy[0] = max(buy[0], sell[0]-prices[i]);
           for(int j=1; j<k+1; j++){
               buy[j] = max(buy[j], sell[j]-prices[i]);
               sell[j] = max(sell[j], buy[j-1]+prices[i]);
           }
       }
       return *max_element(sell.begin(), sell.end());

    }
};