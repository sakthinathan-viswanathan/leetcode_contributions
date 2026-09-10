class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int base = prices[0];

        int max_profit = 0;

        for(int i=1;i<n;i++){
            
            int diff = prices[i] - base;

            max_profit = max(max_profit,diff);


            base = min(base,prices[i]);

            
        }

        return max_profit;
        
    }
};