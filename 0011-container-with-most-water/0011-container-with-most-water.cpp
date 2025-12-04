class Solution {
public:
    int maxArea(vector<int>& height) {

        int i=0;
        int j = height.size()-1;

        int maxheight = 0;

        while(i<j){
            int water = (height[i]>height[j]?height[j]:height[i])*(j-i);
            maxheight = maxheight>water?maxheight:water;

            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }


        }

        return maxheight;
        
    }
};