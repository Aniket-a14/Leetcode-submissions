class Solution {
public:
    vector<string> ans;
    string temp = "";
    map<char,string> mp = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };

    void solve(string digits, int idx){
        if(idx==digits.size()){
            ans.push_back(temp);
            return;
        }

        string val = mp[digits[idx]];

        for(char ch: val){
            temp.push_back(ch);
            solve(digits,idx+1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        solve(digits,0);
        return ans;
    }
};