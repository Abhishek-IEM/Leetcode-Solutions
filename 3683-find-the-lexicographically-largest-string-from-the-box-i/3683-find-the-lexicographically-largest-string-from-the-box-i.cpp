class Solution {
public:
    string answerString(string word, int numF) {
        int n = word.length();

        if(numF == 1) return word;

        string result;

        int lP = n - (numF - 1);

        for(int i = 0; i < n; i++)
        {
            int canTake = min(lP, n - i);
            result = max(result, word.substr(i, canTake));
        }

        return result;
    }
};