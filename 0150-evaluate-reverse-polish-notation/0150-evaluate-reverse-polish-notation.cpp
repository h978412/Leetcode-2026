class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        bool isFound = false;
        int  val = 0;
        for(auto token : tokens){
            if(token != "+" && token != "-" && token != "/" && token != "*" ){
                s.push(std::stoi(token));
                continue;
            }
            int two = s.top();s.pop();
            int one = s.top();s.pop();
            val = this->cal(one,two,token);
            s.push(val);
        }
        return s.top();
    }

    int cal(int one, int two, string op){
        if(op == "*") return one * two;
        if(op == "/") return one / two;
        if(op == "-") return one - two;
        else return one + two;
    }
};