class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX), tmp(n,INT_MAX), pred(n,-1);
        dist[src]=0, tmp[src]=0;
        for(int i=0;i<=k;i++){
            for(auto e:flights){
                if(dist[e[0]]==INT_MAX) continue; //start of edge unreach
                int val = dist[e[0]] + e[2];
                if(val >= tmp[e[1]]) continue; //no improve
                tmp[e[1]] = val; //improve NOT affect this round
                pred[e[1]] = e[0];
            }
            for(int j=0;j<n;j++) dist[j] = tmp[j];
            cout<<"dist: ";
            for(int num:dist) cout<<num<<' ';cout<<"\n";
        }
        return (dist[dst]==INT_MAX)?-1:dist[dst];
    }
};