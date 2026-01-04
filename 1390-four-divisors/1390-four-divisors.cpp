class Solution {
public:

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto num : nums){
            int sum = this->getSum(num);
            if(sum != -1) ans += sum;
        }
        return ans;
    }
    int getSum(int n){
        int cubeRoot = std::round(std::cbrt(n));
        if(cubeRoot*cubeRoot*cubeRoot == n && this->isPrime(cubeRoot)){
            return 1+ cubeRoot + n/cubeRoot + n;
        }
        for(int i=2;i*i<n;i++){
            cout<< i << endl;
            if(n%i == 0){
                if(this->isPrime(i) && this->isPrime(n/i)){
                    return 1+n+i+n/i;
                }
                return -1;
            }
        }
        return -1;
    }


    bool isPrime(int n){
        if(n<2) return false;
        for(int i=2;(i*i <= n);i++){
            if(n%i == 0) return false;
        }
        return true;
    }
};