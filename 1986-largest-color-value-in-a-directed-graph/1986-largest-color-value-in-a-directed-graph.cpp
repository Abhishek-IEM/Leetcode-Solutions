class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int N = colors.size();

        unordered_map<int, vector<int>> adj;

        vector<int> indeg(N, 0);

        for(auto &vec: edges)
        {
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
            indeg[v]++;
        }

        queue<int> q;

        vector<vector<int>> t(N, vector<int> (26, 0));

        for(int i = 0; i < N; i++)
        {
            if(indeg[i] == 0)
            {
                q.push(i);
                t[i][colors[i] - 'a'] = 1;
            }
        }

        int ans = 0, count = 0;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            count++;

            ans = max(ans, t[u][colors[u] - 'a']);

            for(int &v: adj[u])
            {
                for(int i = 0; i < 26; i++)
                {
                    t[v][i] = max(t[v][i], t[u][i] + (colors[v] - 'a' == i));
                }
                indeg[v]--;
                if(indeg[v] == 0) q.push(v);
            }
        }

        if(count < N) return -1;

        return ans;
    }
};