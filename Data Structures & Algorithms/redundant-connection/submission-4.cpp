class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        vector<int> deg(n);
        for(auto v:edges){
            adj[v[0]-1].push_back(v[1]-1);
            adj[v[1]-1].push_back(v[0]-1);
            deg[v[0]-1]++, deg[v[1]-1]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(deg[i]==1) q.push(i);
        vector<int> vis(n); //not in cycle
        while(!q.empty()){
            int u=q.front();q.pop();
            vis[u]=1;
            for(int v:adj[u]){
                deg[v]--;
                if(deg[v]==1) q.push(v);
            }
        }
        for(int i=edges.size()-1; i>-1; i--){
            int u=edges[i][0]-1, v=edges[i][1]-1;
            if(!vis[u] && !vis[v]) return edges[i];
        }
        return vector<int>();
    }
};
