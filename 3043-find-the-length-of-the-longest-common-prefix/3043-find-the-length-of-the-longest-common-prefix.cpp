class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<string,bool> m;
        int ans = 0;
        for(auto num : arr1){
            auto num_str = to_string(num);
            string pre = "";
            for(auto c : num_str){
                pre += c;
                m[pre] = true;
            }
        }
        for(auto num : arr2){
            auto num_str = to_string(num);
            string pre = "";
            for(int i=0;i<num_str.size();i++){
                pre += num_str[i];
                if(m[pre]){
                    ans = max(ans,i+1);
                }
            }
        }

        return ans;

    }
};