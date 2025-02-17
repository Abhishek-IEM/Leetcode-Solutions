class Solution {
public:
    int count;
    void solve(vector<int >&vec)
    {
        count++;

        for(int i = 0; i < 26; i++)
        {
            if(vec[i] == 0) continue;
            vec[i]--;
            solve(vec);
            vec[i]++;
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.length();
        count = 0;
        vector<int> vec(26, 0);
        for(char &ch : tiles) vec[ch - 'A']++;
        solve(vec);
        return count - 1;
    }
};