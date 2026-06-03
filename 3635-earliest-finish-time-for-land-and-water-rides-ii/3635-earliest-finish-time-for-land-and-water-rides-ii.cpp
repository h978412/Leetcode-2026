class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int wmin = INT_MAX, lmin = INT_MAX, ans = INT_MAX;
        //assume land ride end first
        for(int i=0;i<ls.size();i++){
            lmin = min(lmin, ls[i]+ld[i]);
        }
        for(int i=0;i<ws.size();i++){
            int startTime = max(lmin,ws[i]);
            ans = min(ans,startTime+wd[i]);
        }
        //assume water ride end first
        for(int i=0;i<ws.size();i++){
            wmin = min(wmin, ws[i]+wd[i]);
        }
        for(int i=0;i<ls.size();i++){
            int startTime = max(wmin,ls[i]);
            ans = min(ans,startTime+ld[i]);
        }
        return ans;
        
    }
};