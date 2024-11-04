class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string comp = "";
        for(int i = 0; i < n; i++)
        {
            long long freq = 1;
            while(i < n && word[i] == word[i + 1])
            {
                freq++;
                i++;
            }
            while(freq > 9)
            {
                comp += to_string(9) + word[i];
                freq -= 9;
            }
            if(freq > 0) comp += to_string(freq) + word[i];
        }
        return comp;
    }
};