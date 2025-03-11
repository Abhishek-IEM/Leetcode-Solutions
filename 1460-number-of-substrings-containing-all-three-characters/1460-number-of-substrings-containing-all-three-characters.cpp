class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length(), ans = 0;
        vector<int> mp(3, 0);
        int i = 0, j = 0;
        while(j < n)
        {
            char ch = s[j];
            mp[ch - 'a']++;
            
            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0)
            {
                ans += (n - j);
                mp[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};