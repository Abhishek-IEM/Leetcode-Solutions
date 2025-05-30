class Solution {
public:
    void bfs(vector<int>& edges, int node, vector<int>& dist)
    {
        int n = edges.size();

        queue<int> q;
        q.push(node);
        dist[node] = 0;

        vector<bool> visited(n, false);
        visited[node] = true;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            int v = edges[u];

            if(v != -1 && !visited[v])
            {
                visited[v] = true;
                dist[v] = 1 + dist[u];
                q.push(v);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);

        int minDistNode = -1, minDist = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            int maxD = max(dist1[i], dist2[i]);
            if(maxD < minDist)
            {
                minDist = maxD;
                minDistNode = i;
            }
        }
        return minDistNode;
    }
};