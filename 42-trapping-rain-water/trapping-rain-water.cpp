class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right= 0;

        for(int i=0;i<height.size();i++){
            if(height[i]>height[right]){
                right=i;
            }
        }

        int water=0;
        for(int i=1;i<right;i++){
            left= max(left,height[i-1]);
            if(left-height[i]>0){
                water+=left-height[i];
            }
        }

        left=0;
        for(int i=height.size()-2;i>=right;i--){
            left= max(left,height[i+1]);
            if(left-height[i]>0){
                water+=left-height[i];
            }
        }
        return water;
    }
};