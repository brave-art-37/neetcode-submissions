class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int cnt=0;
        vector<bool> vis(n);
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            stack<pair<int,int>> st;
            st.push({i,-1});
            while(!st.empty()){
                int u=st.top().first, p=st.top().second; st.pop();
                if(vis[u]) continue;
                vis[u]=1;
                
                for(int v:adj[u]){
                    if(vis[v] || v==p) continue;
                    st.push({v,u});
                }
            }
            cnt++;
        }
        return cnt;
    }
};
