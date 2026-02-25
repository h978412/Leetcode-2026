class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<multiset<int>> m(33);
        vector<int> ans;

        for(auto num : arr){
            int curr = num;
            int count = 0;
            while(curr){
                if(curr & 1){
                    count++;
                }
                curr = curr >> 1;
            }
            m[count].insert(num);
        }

        for(auto el : m){
            for(auto num : el){
                ans.push_back(num);
            }
        }


        return ans;        
    }
};