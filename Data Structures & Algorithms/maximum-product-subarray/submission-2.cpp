class Solution {
public:
    int maxProduct(vector<int>& nums) {
        bool isit=1; int m=nums.back();
        for(int i=0;i<nums.size()-1;i++){
            isit &= (nums[i]==0 || nums[i+1]==0);
            m = max(m,nums[i]);
        }
        if(isit && m<=0) return m;

        nums.insert(nums.begin(),0);
        nums.push_back(0);
        int n=nums.size();
        //fwd
        int maxi=INT_MIN, neg=1, total=1;
        bool st=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){ //reset
                if(total<0) maxi=max(maxi,total/neg);
                else maxi=max(maxi,total);
                neg=1, total=1, st=0;
            }
            else{
                total*=nums[i];
                if(nums[i]<0 && !st) st=1, neg*=nums[i];
                if(!st) neg*=nums[i];
            }
            //cout<<"total="<<total<<", neg="<<neg<<", st="<<st<<"\n";
        }
        cout<<"\n";

        //bwd
        neg=1, total=1, st=0;
        for(int i=n-1;i>-1;i--){
            if(nums[i]==0){ //reset
                if(total<0) maxi=max(maxi,total/neg);
                else maxi=max(maxi,total);
                neg=1, total=1, st=0;
            }
            else{
                total*=nums[i];
                if(nums[i]<0 && !st) st=1, neg*=nums[i];
                if(!st) neg*=nums[i];
            }
            //cout<<"total="<<total<<", neg="<<neg<<", st="<<st<<"\n";
        }
        return maxi;
    }
};