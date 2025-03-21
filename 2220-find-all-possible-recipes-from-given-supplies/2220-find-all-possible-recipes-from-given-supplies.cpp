class Solution {
public:
    vector<string> findAllRecipes(vector<string>& receipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = receipes.size();
        unordered_set<string> st(supplies.begin(), supplies.end());

        unordered_map<string, vector<int>> adj;
        vector<int> indegree(n, 0);

        for(int i = 0; i < n; i++)
        {
            for(string &ing : ingredients[i])
            {
                if(!st.count(ing)){
                    adj[ing].push_back(i);
                    indegree[i]++;
                }
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0) q.push(i);
        }

        vector<string> result;

        while(!q.empty())
        {
            int i = q.front();
            q.pop();

            string receipe = receipes[i];
            result.push_back(receipes[i]);

            for(int &idx : adj[receipe])
            {
                indegree[idx]--;
                if(indegree[idx] == 0) {
                    q.push(idx);
                }
            }
        }
        return result;
    }
};