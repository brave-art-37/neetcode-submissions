class Solution {
public:
    int calc(vector<int>& a, vector<int>& b){
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& pts) {
        int n=pts.size();
        vector<int> dist(n,INT_MAX), vis(n);
        int next = 0, score=0;
        for(int e=0;e<n;e++){
            int mini=INT_MAX, minIdx=0;
            for(int i=0;i<n;i++){
                if(vis[i]) continue;
                dist[i] = min(dist[i], calc(pts[i], pts[next]));
                if(dist[i]<mini) mini=dist[i], minIdx=i;
            }
            score += mini;
            next = minIdx;
            vis[next] = 1;
        }
        return score;
    }
};
