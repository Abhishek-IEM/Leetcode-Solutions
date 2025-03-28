class Solution {
public:
    vector<int> rank;
    vector<int> parent;

    int find(int x)
    {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int p_x = find(x);
        int p_y = find(y);

        if(p_x !=  p_y)
        {
            if(rank[p_x] > rank[p_y]) parent[p_y] = p_x;
            else if(rank[p_x] < rank[p_y]) parent[p_x] = p_y;
            else
            {
                parent[p_y] = p_x;
                rank[p_x]++;
            }
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);

        for(int i = 0; i < 26; i++) parent[i] = i;

        for(string &s : equations)
        {
            if(s[1] == '=')
            {
                Union(s[0] - 'a', s[3] - 'a');
            }
        }

        for(string &s : equations)
        {
            if(s[1] == '!')
            {
                char first = s[0], second = s[3];

                int parent_first = find(first - 'a');
                int parent_second = find(second - 'a');

                if(parent_first == parent_second) return false;
            }
        }

        return true;
    }
};