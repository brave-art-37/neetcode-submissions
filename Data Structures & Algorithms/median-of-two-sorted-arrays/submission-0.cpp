class Solution {
public:
//binSearch on #elts from smaller arr included in lesser half

//return
//ptr N
//infLoop N
//idxErr N
//oneOff 

    int lastTrue(int lo, int hi, function<bool(int)> f){
        int ans=lo;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(f(mid)) ans=mid, lo=mid+1;
            else hi=mid-1;
        }
        return ans;
    }

    bool valid(int idx, int size){
        return ((idx>-1) && (idx<size));
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //make nums1 smaller
        if(nums2.size()<nums1.size()) nums1.swap(nums2);
        int m=nums1.size(), n=nums2.size();

        int idx1=lastTrue(-1,m-1,[&](int l1){
            // (l1+1) + (l2+1) = (n+m)/2
            int l2 = ((m+n)/2-l1-2); //-1 <= l2 < n always as m<=n

            return (valid(l1,m) && valid(l2+1,n))?(nums1[l1]<=nums2[l2+1]):1;
        });
        int idx2=(m+n)/2-idx1-2;
        if((m+n)%2==1){ //total odd elts
            int ans=INT_MAX;
            if(valid(idx1+1,m)) ans=min(ans,nums1[idx1+1]);
            if(valid(idx2+1,n)) ans=min(ans,nums2[idx2+1]);
            return (double) ans;
        }
        else{ //total even elts
            int more=INT_MAX;
            int less=INT_MIN;
            if(valid(idx1,m)) less=max(less,nums1[idx1]);
            if(valid(idx2,n)) less=max(less,nums2[idx2]);
            if(valid(idx1+1,m)) more=min(more,nums1[idx1+1]);
            if(valid(idx2+1,n)) more=min(more,nums2[idx2+1]);
            return ((double)(more+less))/2;
        }

        nums1.swap(nums2); //undo global changes
    }
};
