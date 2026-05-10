class Solution {
public:
    struct Comp{
        bool operator()(pair<int,char> a, pair<int,char> b){
            return a.first<b.first;
        }  
    };
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        int total=0;
        for(char c:tasks) freq[c-'A']++, total++;
        priority_queue<pair<int,char>, vector<pair<int,char>>, Comp> pq;
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            pq.push({freq[i],(char)('A'+i)});
        }
        queue<pair<int,char>> q;
        for(int i=0;i<n+1;i++) q.push({0,'.'});
        int cnt=0;
        vector<char> sched;
        while(total>0){
            cnt++;
            auto cool = q.front();q.pop();
            if(cool.first>0) pq.push(cool);
            if(pq.empty()){
                q.push({0,'.'});
                sched.push_back('.');
                continue;
            }
            auto add = pq.top();pq.pop();
            sched.push_back(add.second);
            add.first--; total--;
            if(add.first>0) q.push(add);
            else q.push({0,'.'});
            //cout<<"sched: ";for(char c:sched) cout<<c<<' ';cout<<"\n";
        }
        return cnt;
    }
};
