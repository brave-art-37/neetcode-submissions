class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        multiset<int> sum, tmp;
        sum.insert(0);
        for(int num:nums){
            for(int s:sum){
                tmp.insert(s+num);
                tmp.insert(s-num);
            }
            sum = tmp;
            tmp.clear();
            //cout<<"sum: ";for(int num:sum) cout<<num<<' ';cout<<"\n";
        }
        return sum.count(target);
    }
};