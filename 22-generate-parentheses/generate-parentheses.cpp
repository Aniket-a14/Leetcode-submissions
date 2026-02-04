class Solution {
public:
    vector<string> ans;
    void solve(int n, string& temp,int open,int close){
        if(temp.length()==2*n) ans.push_back(temp);

        if(open<n){
            temp.push_back('(');
            solve(n,temp,open+1,close);
            temp.pop_back();
        }

        if(close<open){
            temp.push_back(')');
            solve(n,temp,open,close+1);
            temp.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        solve(n,temp,0,0);
        return ans;
    }
};