class Solution {
public:
    struct Comp{
        bool operator()(vector<int>& a, vector<int>& b){
            return (a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1]);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Comp> pq;
        for(auto p:points){
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> pts;
        while(!pq.empty()){
            auto p=pq.top();pq.pop();
            pts.push_back(p);
        }
        return pts;
    }
};