class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        if(n < 3) return false;

        bool vowel = false, cons = false;

        for(char ch : word)
        {
            if(isalpha(ch))
            {
                ch = tolower(ch);
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') vowel = true;
                else cons = true;
            }
            else if(!isdigit(ch)) return false;
        }

        return vowel && cons;
    }
};