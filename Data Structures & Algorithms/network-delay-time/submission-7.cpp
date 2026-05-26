class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        k--;
        vector<vector<pair<int,int>>> adj(n);
        for(auto p:times){
            int u=p[0], v=p[1], t=p[2];u--,v--;
            adj[u].push_back({v,t});
        }
        priority_queue<pair<int,int>> pq; //(-dist,node) contain gray nodes
        vector<int> dist(n,INT_MAX), vis(n);
        pq.push({0,k});dist[k]=0;
        while(!pq.empty()){
            auto [d,u] = pq.top(); pq.pop();
            if(-d > dist[u]) continue; //older data
            vis[u]=1; //u now black
            for(auto [v,t]:adj[u]){
                if(vis[v]) continue; //already black
                if(dist[u]+t < dist[v]) {
                    dist[v] = dist[u]+t;
                    pq.push({-dist[v],v}); //v now gray
                }
            }
        }
        int maxi=0;
        for(int num:dist) maxi=max(maxi,num);
        return (maxi==INT_MAX)?-1:maxi;
    }
};