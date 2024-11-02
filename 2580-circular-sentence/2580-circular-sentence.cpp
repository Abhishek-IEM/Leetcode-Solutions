class Solution {
public:
    bool isCircularSentence(string s) {
        int n = s.length();
        for(int i = 0; i < n - 1; i++)
        {
            char ch;
            while(i < n && s[i] != ' ')
            {
                ch = s[i];
                i++;
            }
            if(i < n && ch != s[i+1]) return false;
        }
        if(s[n - 1] != s[0]) return false; 
        return true;
    }
};