class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        long m = mass;
        bool isDestroid = true;
        for(auto num : a){
            if(num <= m) m += num;
            else return false;
        }
        return true;
        
    }
};