class Solution {
public:
    int maxProfit(vector<int>& prices) {
        map<int,bool> m;
        m[prices[0]] = true;
        int maxProfit = 0;
        for(int i=1;i<prices.size();i++){
            int profit = prices[i] - m.begin()->first ;
            maxProfit = max(profit,maxProfit);
            m[prices[i]] = true;
        }
        return maxProfit;
    }
};