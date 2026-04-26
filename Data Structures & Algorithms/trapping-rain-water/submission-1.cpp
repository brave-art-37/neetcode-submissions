class Solution {
   public:
    int trap(vector<int>& height) {
        int lmax = 0, rmax = 0;
        int l = 0, r = height.size() - 1;
        int total = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                if(lmax<height[l]) lmax=height[l];
                else total+=lmax-height[l];
                l++;
            } else {
                if(rmax<height[r]) rmax=height[r];
                else total+=(rmax-height[r]);
                r--;
            }
        }
        return total;
    }
};
