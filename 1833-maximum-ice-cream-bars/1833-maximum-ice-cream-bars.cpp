class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs),end(costs));
        int count = 0;
        for(auto& cost : costs){
            if(cost > coins) break;
            coins -= cost;
            count++;
        }
        return count;
        
    }
};