class Solution {
public:
    int ladderLength(string b, string e, vector<string>& words) {

        if( find(words.begin(), words.end(), e) == words.end() ) return 0;

        map<string,int> cmp;
        int cnt=0;
        for(string s:words) cmp[s]=cnt, cnt++;
        vector<vector<int>> adj(cnt);
        int n=b.size();
        for(string s:words){
            for(int i=0;i<n;i++){ //which idx letter change
                for(int j=0; j<26;j++){
                    char c = j+'a';
                    string tmp=s; tmp[i]=c;
                    if(c==s[i] || !cmp.count(tmp)) continue;
                    adj[cmp[s]].push_back(cmp[tmp]);
                }
            }
        }

        for(auto p:cmp) cout<<p.first<<' '<<p.second<<"\n";
        for(int i=0;i<cnt;i++){
            auto v = adj[i];
            cout<<words[i]<<": ";
            for(int num:v) cout<<num<<' ';cout<<"\n";
        }

        int mini = INT_MAX;
        for(int i=0;i<n;i++){ //which idx to sub
            for(int j=0;j<26;j++){ //to subs with what
                char c = (char) j+'a';
                string tmp = b; tmp[i]=c;
                if(!cmp.count(tmp)) continue; //not in words

                queue<int> q; q.push(cmp[tmp]); //bfs as dijkstra
                vector<int> vis(cnt);
                int layer=q.size(), lvl=0, fnd=0;
                while(!q.empty()){
                    lvl++;
                    while(layer-->0){
                        int u=q.front();q.pop();
                        if(cmp[e]==u) {
                            fnd=1;
                            break;
                        }
                        for(int v:adj[u]){
                            if(vis[v]) continue; //already queued
                            vis[v]=1;
                            q.push(v);
                        }
                    }
                    if(fnd) break;
                    layer = q.size();
                }
                if(fnd) mini = min(mini,lvl+(b[i]!=c));
            }
        }
        return (mini==INT_MAX)?0:mini;
    }
};