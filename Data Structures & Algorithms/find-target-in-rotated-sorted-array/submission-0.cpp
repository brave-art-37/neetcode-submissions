class Solution {
public:
// find idx of min elt, this split into 2 sorted arrs
// apply binSearch on one of them

//return N
//infLoops N
//idxErr N
//ptr N

    int firstTrue(int lo, int hi, function<bool(int)> f){
        int ans = hi;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(f(mid)) ans=mid, hi=mid-1;
            else lo=mid+1;
        }
        return ans;
    }

    int search(vector<int>& nums, int target) {
        //find min elt idx
        int n=nums.size();
        int idx=firstTrue(0,n-1, [&](int i){
            return (nums[i]<nums[n-1]); //first idx with val smaller than last elt
        });

        //not in arr
        if(target<nums[idx] || (target>nums[(n+idx-1)%n])) return -1;
        else if(target>nums[n-1]){ //ie present in first part
            int j=firstTrue(0,idx-1,[&](int i){
                return (nums[i]>=target);
            });
            return (nums[j]==target)?j:-1;
        }
        else{ //ie present in second part
             int j=firstTrue(idx,n-1,[&](int i){
                return (nums[i]>=target);
            });
            return (nums[j]==target)?j:-1;       
        }
        return -1;
    }
};
