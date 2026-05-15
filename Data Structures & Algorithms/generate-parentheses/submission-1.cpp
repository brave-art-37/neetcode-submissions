class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n<=0) return vector<string>(1,"");
        else if(n==1) return vector<string>(1,"()");
        int k=1;
        vector<string> res;
        for(;2*n-k-1>=0;k+=2){
            vector<string> v1=generateParenthesis((k-1)/2), v2=generateParenthesis((2*n-k-1)/2);
            for(string s1:v1){
                for(string s2:v2){
                    string s='('+s1+')'+s2;
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};