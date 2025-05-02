class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = "L" + dominoes + "R";
        int n    = s.length();
        string result = "";
        for(int i = 0, j = 1; j<n; j++) {
            if(s[j] == '.') continue;
            
            int midPartLength = j-i-1;
            if(i > 0)
                result.push_back(s[i]);
            
            if(s[i] == s[j])
                result += string(midPartLength, s[i]);
            else if(s[i] == 'L' && s[j] == 'R')
                result += string(midPartLength, '.');
            else
                result += string(midPartLength/2, 'R') + string(midPartLength%2, '.') + string(midPartLength/2, 'L');
            i = j;
        }
        
        return result;
    }
};