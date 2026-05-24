class Solution {
public:

    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> indeg(n);
        vector<vector<int>> out(n);
        for(auto v:pre){
            indeg[v[1]]++;
            out[v[0]].push_back(v[1]);
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(indeg[i]==0) q.push(i);
        int pp=0;
        vector<int> topo; set<int> isit;
        while( !q.empty() ){
            int u=q.front();
            q.pop(); pp++;topo.push_back(u);
            if(isit.count(u)) return 0;
            isit.insert(u);
            for(int v:out[u]) {
                indeg[v]--;
                if(indeg[v]==0) q.push(v);
            }
        }
        return (pp==n);
    }
};
