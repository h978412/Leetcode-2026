class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>m(amount+1,vector<int>(coins.size()+1,-2));
        return this->rec(coins,coins.size(),amount,m);
    }
    int rec(vector<int>& coins,int i, int amount,vector<vector<int>>& m){

        if(m[amount][i] != -2) return m[amount][i]; 
        if(amount == 0) return 0;
        if(i == 0) return -1;

        int count1=-1,count2=-1;
        if(coins[i-1] <= amount){
            count1 = this->rec(coins,i,(amount-coins[i-1]),m);
        }
        count2 = this->rec(coins,i-1,amount,m);
        if(count1 == -1 && count2 == -1) m[amount][i] = -1;
        else if(count1 == -1) m[amount][i] =  count2;
        else if(count2 == -1) m[amount][i] =  count1+1;
        else m[amount][i] =  min(count1+1,count2);
        return m[amount][i];
    }
};