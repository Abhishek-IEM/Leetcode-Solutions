class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int m = s.size(), n = spaces.size(), j = 0;
        for(int i = 0; i < m; i++)
        {
            if(j < n && i == spaces[j]) 
            {
                ans += " ";
                j++;
            }
            ans += s[i];
        }
        return ans;
    }
};