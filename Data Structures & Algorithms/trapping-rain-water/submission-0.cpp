class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> maxl(n), maxr(n);
        for(int i=0;i<n;i++){
            if(i==0) continue;
            maxl[i]=max(maxl[i-1],height[i-1]);
        }
        for(int i=n-1;i>-1;i--){
            if(i==n-1) continue;
            maxr[i]=max(maxr[i+1],height[i+1]);
        }
        int total=0;
        for(int i=0;i<n;i++){
            total+=max(0, min(maxl[i],maxr[i])-height[i]);
        }
        return total;
    }
};
