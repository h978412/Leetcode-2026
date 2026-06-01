class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int finalCost = 0;
        sort(cost.begin(),cost.end(),greater<int>());
        int count = 0;
        for(auto num : cost){
            if(count == 2) count = 0;
            else{
                finalCost += num;
                count++;
            }
        }

        return finalCost;
        
    }
};