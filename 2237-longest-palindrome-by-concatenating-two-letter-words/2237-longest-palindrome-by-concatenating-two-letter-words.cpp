class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0;

        for(string &word: words)
        {
            string rev = word;
            swap(rev[0], rev[1]);

            if(mp[rev] > 0)
            {
                ans += 4;
                mp[rev]--;
            }
            else mp[word]++;
        }

        for(auto &it: mp)
        {
            string word = it.first;
            int count = it.second;

            if(word[0] == word[1] && count > 0)
            {
                ans += 2;
                break;
            }
        }

        return ans;
    }
};