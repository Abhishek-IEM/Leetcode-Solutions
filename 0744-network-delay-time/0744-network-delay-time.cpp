class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i = 0; i < times.size(); i++)
        {
            int u = times[i][0], v = times[i][1], wt = times[i][2];
            adj[u].push_back({v, wt});
        }

        vector<int> result(n + 1, INT_MAX);

        result[k] = 0;
        pq.push({0, k});

        while(!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto &vec : adj[node])
            {
                int adjNode = vec.first;
                int dist = vec.second;

                if(d + dist < result[adjNode])
                {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans = max(ans, result[i]);
        }    

        return ans == INT_MAX ? -1 : ans;
    }
};