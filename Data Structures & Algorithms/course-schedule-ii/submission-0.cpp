class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> indeg(n);
        vector<vector<int>> out(n);
        for(auto v:pre){
            indeg[v[0]]++;
            out[v[1]].push_back(v[0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(indeg[i]==0) q.push(i);
        int pp=0; vector<int> topo; set<int> isit;
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(isit.count(u)) break;
            pp++; topo.push_back(u); isit.insert(u);
            for(int v:out[u]){
                indeg[v]--;
                if(indeg[v]==0) q.push(v);
            }
        }
        if(pp!=n) return vector<int>();
        else return topo;
    }
};
