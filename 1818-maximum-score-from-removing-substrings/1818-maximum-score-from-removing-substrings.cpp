class Solution {
public:
    string removeSubstr(string &s, string &match)
    {
        int i = 0;

        for(int j = 0; j < s.length(); j++)
        {
            s[i] = s[j];
            i++;
            if(i >= 2 && s[i - 2] == match[0] && s[i - 1] == match[1]){
                i -= 2;
            }
        }

        s.erase(begin(s) + i, end(s));
        return s;
    }
    int maximumGain(string s, int x, int y) {
        int n = s.length(), score = 0;

        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (maxStr == "ba") ? "ab" : "ba";

        string first = removeSubstr(s, maxStr);
        int l = first.length();
        int charRemoved = n - l;
        score += (charRemoved / 2 )* max(x, y);

        string second = removeSubstr(first, minStr);
        int m = second.length();
        charRemoved = l - m;
        score += (charRemoved / 2 )* min(x, y);

        return score;
    }
};