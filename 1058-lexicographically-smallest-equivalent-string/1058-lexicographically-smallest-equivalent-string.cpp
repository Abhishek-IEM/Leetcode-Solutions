class Solution {
public:
    char BFS(unordered_map<char, vector<char>> &adj, char ch, vector<int> &visited)
    {
        queue<char> q;
        q.push(ch);

        char minChar = ch;

        visited[ch - 'a'] = 1;

        while(!q.empty())
        {
            char c = q.front();
            q.pop();

            minChar = min(minChar, c);

            for(char &v : adj[c])
            {
                if(!visited[v - 'a'])
                {
                    visited[v - 'a'] = 1;
                    q.push(v);
                }
            }
        }

        return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length(), m = baseStr.length();

        unordered_map<char, vector<char>> adj;

        for(int i = 0; i < n; i++)
        {
            char u = s1[i], v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string result;

        for(int i = 0; i < m; i++)
        {
            char ch = baseStr[i];
            vector<int> visited(26, 0);
            char minChar = BFS(adj, ch, visited);
            result.push_back(minChar);
        }

        return result;
    }
};