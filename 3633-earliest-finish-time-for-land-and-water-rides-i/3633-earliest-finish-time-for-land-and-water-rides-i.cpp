class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int minWaterRide = INT_MAX;
        int miLandRide = INT_MAX;
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        //assume land ride ends first
        for(int i=0;i<ls.size();i++){
            miLandRide = min(miLandRide,ld[i]+ls[i]);
        }

        for(int i=0;i<ws.size();i++){
            int endTime = max(miLandRide,ws[i]) + wd[i];
            min1 = min(min1,endTime);
        }





        //assume water ride ends first
        for(int i=0;i<ws.size();i++){
            minWaterRide = min(minWaterRide,ws[i]+wd[i]);
        }
        for(int i=0;i<ls.size();i++){
            int endTime = max(minWaterRide,ls[i]) + ld[i];
            min2 = min(min2,endTime);
        }

        return min(min1,min2);

    }
};