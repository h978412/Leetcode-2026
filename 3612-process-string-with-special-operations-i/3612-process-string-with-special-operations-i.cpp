class Solution {
public:
    string str;
    string processStr(string s) {
        this->str = s;
        return this->func("",0);

    }

    string func(string temp, int i){
        if(i == this->str.size()) return temp;
        auto c = this->str[i];
        if(c == '*'){
            if(temp != ""){
                temp.pop_back();
            }
        }else if(c == '#'){
            temp += temp;
        }else if(c == '%'){
            reverse(temp.begin(), temp.end());
        }else{
            temp += c;
        }
        return this->func(temp,i+1);
    }
};