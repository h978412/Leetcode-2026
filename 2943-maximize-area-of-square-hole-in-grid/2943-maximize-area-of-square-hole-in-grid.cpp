class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        std::sort(hBars.begin(),hBars.end());
        std::sort(vBars.begin(),vBars.end());

        int maxHorizontal=INT_MIN,horizontal;
        int maxVertical = INT_MIN, vertical;


        for(int i=0;i<hBars.size();i++){
            // cout << hBars[i] << endl;
            if(i ==0 || hBars[i] != hBars[i-1]+1){
                horizontal = 1;
            }else{
                horizontal++;
            }
            maxHorizontal = std::max(maxHorizontal,horizontal);
        }


        for(int i=0;i<vBars.size();i++){
            if(i ==0 || vBars[i] != vBars[i-1]+1){
                vertical = 1;
            }else{
                vertical++;
            }
            maxVertical = std::max(maxVertical,vertical);
        }

        

        int ans =  std::min(maxVertical,maxHorizontal);
        return (ans+1)*(ans+1);
        
    }
};