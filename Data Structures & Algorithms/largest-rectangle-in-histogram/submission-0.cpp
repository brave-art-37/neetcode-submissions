class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> right(n),left(n);
        stack<int> stR,stL;
        //first to right greater
        for(int i=0;i<n;i++){
            while(!stR.empty() && heights[stR.top()]>heights[i]){
                right[stR.top()]=(i-1);
                stR.pop();
            }
            stR.push(i);
        }
        while(!stR.empty()) right[stR.top()]=(n-1), stR.pop();

        //first to left greater
        for(int i=n-1;i>-1;i--){
            while(!stL.empty() && heights[stL.top()]>heights[i]){
                left[stL.top()]=(i+1);
                stL.pop();
            }
            stL.push(i);
        }
        while(!stL.empty()) left[stL.top()]=0, stL.pop();

        int ans=0;
        for(int i=0;i<n;i++) ans=max(ans,heights[i]*(right[i]-left[i]+1));
        return ans;
    }
};
