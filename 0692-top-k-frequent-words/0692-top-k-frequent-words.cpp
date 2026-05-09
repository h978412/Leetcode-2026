class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        vector<string> ans;
        for(auto word : words){
            m[word] += 1;
        }

        for(int i=0;i<k;i++){
            string word = m.begin()->first;
            int frequency = m.begin()->second;
            for(auto it = m.begin();it!= m.end();it++){
                if(frequency < it->second){
                    frequency = it->second;
                    word = it->first;
                }
            }
            ans.push_back(word);
            m[word] = 0;
        }
        return ans;
    }
};