class Solution {
public:
    int bfs(int n, unordered_map<int, vector<int>> &adj)
    {
        queue<int> q;
        q.push(0); //source node
        vector<bool> visited(n, false);
        visited[0] = true;
        int levels = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int node = q.front();
                q.pop();
                if(node == n - 1) return levels;
                for(int &nbr : adj[node])
                {
                    if(!visited[nbr])
                    {
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }
            levels++;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i <= n - 2; i++)
        {
            adj[i].push_back(i + 1);
        }
        vector<int> result;
        for(auto &query : queries)
        {
            int u = query[0];
            int v = query[1];
            adj[u].push_back(v);
            int d = bfs(n, adj);
            result.push_back(d);
        }
        return result;
    }
};