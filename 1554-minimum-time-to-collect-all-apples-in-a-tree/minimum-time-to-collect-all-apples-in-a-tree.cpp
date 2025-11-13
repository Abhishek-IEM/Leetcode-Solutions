class Solution {
public:
    int DFS(unordered_map<int, vector<int>> &adj, int curr, int parent, vector<bool>& hasApple) 
    {
        int time = 0;
        for(int &child: adj[curr])
        {
            if(child == parent) continue;
            int t = DFS(adj, child, curr, hasApple);
            if(t > 0 || hasApple[child]) time += t + 2;
        }

        return time;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adj;

        for(auto &vec : edges)
        {
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return DFS(adj, 0, -1, hasApple);
    }
};