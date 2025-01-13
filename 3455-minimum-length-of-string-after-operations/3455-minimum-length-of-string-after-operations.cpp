class Solution {
public:
    int minimumLength(string s) {
        int n = s.length(), deleted = 0;
        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
            if(freq[s[i] - 'a'] == 3)
            {
                freq[s[i] - 'a'] -= 2;
                deleted += 2;
            }
        }
        return n - deleted;
    }
};