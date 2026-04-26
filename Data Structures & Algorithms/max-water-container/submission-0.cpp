class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0, r=heights.size()-1;
        int maxi=0;
        while(l<r){
            maxi=max(maxi,(r-l)*min(heights[l],heights[r]));
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        return maxi;
    }
};
