class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        vector<int> adj[n];
        vector<int> inDegree(n, 0);
        for(int i = 0; i < m; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int j = 0; j < adj[node].size(); j++)
            {
                inDegree[adj[node][j]]--;
                if(!inDegree[adj[node][j]])
                q.push(adj[node][j]);
            }
        }
        return ans.size() == n ? true : false;
    }
};