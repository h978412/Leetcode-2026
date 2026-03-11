class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        // int bitwidth = std::bit_width(n);
        int temp = 0;
        while(n>>temp){
            temp++;
        }
        int val = (1 << temp) -1;
        return n^val;
    }
};