class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>m(amount+1,vector<int>(coins.size()+1));
        for(int i=0;i<=coins.size();i++){
            m[0][i] = 0;
        }
        for(int i=1;i<=amount;i++){
            m[i][0] = -1;
        }

        for(int i=1;i<=amount;i++){
            for(int j=1;j<=coins.size();j++){
                int count1 =-1, count2 =-1;
                //if i chose to use the current element
                if(i>= coins[j-1]){
                    count1 = m[i-coins[j-1]][j];
                }
                //if i chose to not use current element
                count2 = m[i][j-1];
                if(count1 == -1 && count2 ==-1) m[i][j] = -1;
                else if(count1 == -1) m[i][j] = count2;
                else if(count2 == -1) m[i][j] = count1+1;
                else m[i][j] = min(count1+1,count2);
            }
        }

        return m[amount][coins.size()];
    }

};