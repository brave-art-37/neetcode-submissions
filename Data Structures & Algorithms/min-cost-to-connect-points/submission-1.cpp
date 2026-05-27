class Solution {
public:
    int dist(vector<int>& a, vector<int>& b){
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& pts) {
        int score=0;
        unordered_set<int> used, notUsed;
        used.insert(0);
        for(int i=1;i<pts.size();i++) notUsed.insert(i);
        while(!notUsed.empty()){
            int mini=INT_MAX, minIdx=-1;
            for(int i:used){
                for(int j:notUsed){
                    int val = dist(pts[i], pts[j]);
                    if(val>=mini) continue;
                    mini = val;
                    minIdx = j;
                }
            }
            notUsed.erase(minIdx);
            used.insert(minIdx);
            score += mini;
        }
        return score;
    }
};