class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=0;
       for(int i=0,j=height.size()-1;i<j;){
           maxarea= max(maxarea,min(height[i],height[j])*(j-i));
           (height[i]>height[j])? j--:i++;
       }
        return maxarea;
    }
};