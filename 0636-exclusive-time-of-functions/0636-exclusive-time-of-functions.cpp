class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);
        int totalTime = 0;
        stack<vector<int>> s;

        for(int i=0;i<logs.size();i++){
            std::stringstream ss(logs[i]);
            std::string segment;
            std::vector<std::string> results;
            while (std::getline(ss, segment, ':')) {
            results.push_back(segment);
            }

            if(results[1]== "start"){
                if(!s.empty()){
                    s.top()[1] += totalTime;
                }
                s.push(vector<int>{std::stoi(results[2]),0});
                totalTime = 0;

            }else{
                totalTime += s.top()[1];
                int timeSpent = (std::stoi(results[2]) - s.top()[0] + 1 - totalTime);
                ans[std::stoi(results[0])] += timeSpent;
                totalTime += timeSpent;
                s.pop();
            }

        }
        return ans;
        
    }
};