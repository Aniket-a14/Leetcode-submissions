class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.length()-1]=='1') return false;
        int n = s.size()-1;
        queue<int> q;
        q.push(0);
        int farthest = 0;

        while(!q.empty()){
            int node = q.front();q.pop();
            int left = max(node + minJump,farthest+1);
            int right = min(node+ maxJump,n);

            for(int i=left;i<=right;i++){
                if(s[i]=='0'){
                    if(i==s.length()-1) return true;
                    q.push(i);
                }
            }
            farthest = right;
        }

        return false;
    }
};