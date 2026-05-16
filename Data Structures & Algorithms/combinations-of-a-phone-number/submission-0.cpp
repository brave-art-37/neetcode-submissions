class Solution {
public:
    map<int,vector<char>> data = {
        {2, {'a','b','c'}},
        {3, {'d','e','f'}},
        {4, {'g','h','i'}},
        {5, {'j','k','l'}},
        {6, {'m','n','o'}},
        {7, {'p','q','r','s'}},
        {8, {'t','u','v'}},
        {9, {'w','x','y','z'}}
    };
    vector<string> res;
    string word;

    //letters used till idx in digits
    void recurr(string digits, int idx){
        if(idx==digits.size()){
            res.push_back(word);
            return;
        }
        for(char c:data[digits[idx]-'0']){
            word = word + c;
            recurr(digits,idx+1);
            word.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string>();
        recurr(digits,0);
        return res;
    }
};
