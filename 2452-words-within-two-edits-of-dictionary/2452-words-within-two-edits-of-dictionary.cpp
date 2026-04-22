class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(auto q : queries){
            for(auto d : dictionary){
                int distance = 0;
                for(int i=0;i<q.size();i++){
                    if(distance > 2) break;
                    if(d[i] != q[i]) distance++;

                }
                if(distance <=2){
                    ans.push_back(q);
                    break;
                }
            }
        }

        return ans;
        
    }
};