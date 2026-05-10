class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int num:stones) pq.push(num);

        while(pq.size()>1){
            int x=pq.top();pq.pop();
            int y=pq.top();pq.pop();
            if(x!=y) pq.push(abs(x-y));
        }

        if(pq.empty()) return 0;
        else if(pq.size()==1) return pq.top();
    }
};
