class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        vector<int> INdeg(n, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            INdeg[prerequisites[i][1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (INdeg[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            count++;

            for (int j = 0; j < adj[node].size(); j++) {
                INdeg[adj[node][j]]--;
                if (INdeg[adj[node][j]] == 0) q.push(adj[node][j]);
            }
        }

        return count == n;
    }
};
