class Solution {
public:
    int length(int left, int right, string &s)
    {
        int len = 0;
        while(left >= 0 && right < s.size())
        {
            if(s[left] == s[right])
            {
                len += 2;
                left--;
                right++;
            }
            else break;
        }
        return len;
    }
    
    string longestPalindrome(string s) {
        int n = s.size(), maxLen = 1, start = 0;
        //odd
        for(int i = 0; i < n; i++)
        {
            int len = 1 + length(i - 1, i + 1, s);
            if(len > maxLen)
            {
                maxLen = len;
                start = i - len / 2;
            }
        }
         //even
        for(int i = 1; i < n; i++)
        {
            int len = length(i - 1, i, s);
            if(len > maxLen)
            {
                maxLen = len;
                start = i - len / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};