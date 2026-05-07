class Solution {
public:
//first idx st val < last elt
// return N
// infLoop N
// idxErr N
// ptr N

    int firstTrue(int lo, int hi, function<bool(int)> f){
        int ans=hi;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(f(mid)) ans=mid, hi=mid-1;
            else lo=mid+1;
        }
        return ans;
    }

    int findMin(vector<int> &nums) {
        int n=nums.size();
        return nums[firstTrue(0,n-1,[&](int i){
            return (nums[i]<nums[n-1]);
        })];
    }
};
