class Solution {
public:
    int divisorSum[100001] = {0};
    unordered_map<int,bool> primeList;
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto num : nums){
            if(divisorSum[num] == 0){
                int sum = this->getSum(num);
                divisorSum[num] = sum;
            }
            int sum = divisorSum[num];
            if(sum != -1) ans += sum;
        }
        return ans;
    }
    int getSum(int n){
        int cubeRoot = std::round(std::cbrt(n));
        if(cubeRoot*cubeRoot*cubeRoot == n && this->checkIfPrime(cubeRoot)){
            return 1+ cubeRoot + n/cubeRoot + n;
        }
        for(int i=2;i*i<n;i++){
            // cout<< i << endl;
            if(n%i == 0){
                // cout << "n is divisabel by " << i << endl;  
                if(this->checkIfPrime(i) && this->checkIfPrime(n/i)){
                    // cout << "i is prime number " << i << endl;
                    return 1+n+i+n/i;
                }
                return -1;
            }
        }
        return -1;
    }

    bool checkIfPrime(int n){
        if(primeList.find(n) != primeList.end()){
            return primeList[n];
        }
        int isPrimeNumber = this->isPrime(n);
        primeList[n] = isPrimeNumber;
        return isPrimeNumber;

    }

    bool isPrime(int n){
        if(n<2) return false;
        for(int i=2;(i*i <= n);i++){
            if(n%i == 0) return false;
        }
        return true;
    }
};