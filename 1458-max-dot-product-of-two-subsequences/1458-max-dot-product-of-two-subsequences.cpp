class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>m(nums1.size()+1,vector<int>(nums2.size()+1,INT_MIN));
        return this->rec(nums1,nums2,nums1.size(),nums2.size(),m);   
    }
    int rec(vector<int>& nums1, vector<int>& nums2, int i, int j,vector<vector<int>>& m){
        if(m[i][j] != INT_MIN) return m[i][j];
        if(i==0 || j ==0) return INT_MIN;
        long long product = nums1[i-1]*nums2[j-1];
        int sum1 = this->rec(nums1,nums2,i-1,j,m);
        int sum2 = this->rec(nums1,nums2,i,j-1,m);
        long long sum3 = this->rec(nums1,nums2,i-1,j-1,m);
        sum3 = max(product,sum3+product);
        int ans =  max(max(sum1,sum2),(int)sum3);
        m[i][j] = ans;
        return ans;
    }
};