class Solution {
    StringBuilder str;
    public String processStr(String s) {
        this.str = new StringBuilder(s);
        StringBuilder temp = new StringBuilder("");
        return this.func(temp,0).toString();

    }

    private StringBuilder func(StringBuilder s, int i){
        if(i == this.str.length()) return s;
        char c = this.str.charAt(i); 
        if(c == '*'){
            if(s.length() != 0){
                s.deleteCharAt(s.length()-1);
            }

        }else if(c == '#'){
            s.append(s);
        }else if(c == '%'){
            s.reverse();
        }else{
            s.append(c);
        }
        return this.func(s,i+1);
        

    }
}