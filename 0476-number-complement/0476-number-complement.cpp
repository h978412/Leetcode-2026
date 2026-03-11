class Solution {
public:
    int findComplement(int n) {
                if(n==0) return 1;
        // int bitwidth = std::bit_width(n);
        unsigned int temp = 0;
        while(n>>temp){
            temp++;
        }
        long long val = (1L << temp) -1;
        return n^val;
    }
};