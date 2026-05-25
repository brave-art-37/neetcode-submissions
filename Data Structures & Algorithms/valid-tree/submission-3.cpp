class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto v:edges){
            adj[v[1]].push_back(v[0]);
            adj[v[0]].push_back(v[1]);
            if(v[0]==v[1]) return 0; //self loop
        }
        vector<int> topo, vis(n); int cnt=0;
        stack<pair<int,int>> st;
        st.push({0,-1});
        while(!st.empty()){
            int u = st.top().first, p=st.top().second;
            if(vis[u]) return 0; //cycle
            st.pop(); cnt++; vis[u]=1;
            for(int v:adj[u]){
                if(vis[v] || v==p) continue;
                st.push({v,u});
            }
        }
        return (cnt==n);
    }
};
