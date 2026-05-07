class Solution {
public:
// inf loop N
// return N
// idxError N
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

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int hi=*max_element(piles.begin(),piles.end());
        return firstTrue(1, hi, [&](int k){
            int hrs=0;
            for(int i=0;i<n;i++){
                hrs+=(piles[i]+k-1)/k;
            }
            return (hrs<=h);
        });
    }
};
