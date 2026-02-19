class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& graph){
        for(auto ch: graph[node]){
            if(vis[ch]==0){
                vis[ch] = (vis[node]==1?2:1);
                if(dfs(ch,vis,graph)==false) return false;
            }else{
                if(vis[ch]==vis[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vis[i]=1;
                if(dfs(i,vis,graph)==false) return false;
            }
        }

        return true;
    }
};