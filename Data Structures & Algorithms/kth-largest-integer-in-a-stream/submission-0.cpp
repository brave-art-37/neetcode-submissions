class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int size;

    KthLargest(int k, vector<int>& nums):pq(), size(k) {
        for(int num:nums){
            add(num);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size) pq.pop();
        return pq.top();
    }
};
