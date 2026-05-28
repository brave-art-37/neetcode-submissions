class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        map<char,vector<char>> adj;
        vector<bool> used(26);
        for(string s:words) for(char c:s) used[c-'a']=1;
        for(int i=1;i<words.size();i++){
            string s=words[i-1], t=words[i];
            int k = 0, fnd=0;
            while(k<s.size() && k<t.size() && s[k]==t[k]) k++;
            if(k<s.size() && k<t.size()) {
                fnd = 1;
                adj[s[k]].push_back(t[k]);
            }
            if(!fnd && t.size()<s.size()) return ""; //t is pref of s
        }
        /*
        cout<<"adj:\n";
        for(auto p:adj){
            cout<<p.first<<": ";
            for(auto q:p.second) cout<<q<<' ';
            cout<<"\n";
        }
        */
        string res = "";
        vector<int> vis(26);
        for(int c='a';c<='z';c++){
            if(!used[c-'a'] || vis[c-'a']) continue;
            stack<char> st;
            st.push(c);
            while(!st.empty()){
                int d=st.top();
                if(vis[d-'a']==2) { st.pop(); continue; } //fully done
                else if(vis[d-'a']==1){ //kids done
                    vis[d-'a']=2;
                    st.pop();
                    res+=d;
                }
                else{
                    vis[d-'a']=1;
                    if(!adj.count(d)) continue;
                    for(char e:adj[d]){
                        if(vis[e-'a']==1) return ""; //cycle
                        else if(vis[e-'a']==2) continue;
                        st.push(e);
                    }
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};