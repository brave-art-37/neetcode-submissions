class Solution {
public:
    int n;
    vector<int> vis, cycle;
    vector<vector<int>> adj;
    int start=0, fnd=0;

    void dfs(int s, int e){
        
        cout<<"s="<<s<<", e="<<e<<"( \n";
        cout<<"st="<<start<<", fnd="<<fnd<<"\n";
        
        if(fnd) {
            cout<<")\n";
            return;
        }
        if(vis[s]){
            start = s;
            cout<<")\n";
            return;
        }
        vis[s]=1;
        for(int v:adj[s]){
            if(v==e || start!=0) continue;
            dfs(v,s);
        }
        if(start!=0 && !fnd) cycle.push_back(s);
        if(s==start) fnd=1; //cycle complete
        cout<<")\n";
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        adj = vector<vector<int>>(n+1);
        vis = vector<int>(n+1);
        for(auto v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        dfs(1,0);
        cout<<"cycle: ";for(int num:cycle) cout<<num<<' ';
        set<pair<int,int>> pre;
        for(int i=0;i<cycle.size();i++){
            pre.insert({ cycle[i], cycle[(i+1)%cycle.size()] });
            pre.insert({ cycle[(i+1)%cycle.size()], cycle[i] });
        }
        for(int i=edges.size()-1; i>-1; i--){
            auto v = edges[i];
            if(!pre.count({v[0],v[1]})) continue;
            return v;
        }
        return vector<int>();
    }
};
