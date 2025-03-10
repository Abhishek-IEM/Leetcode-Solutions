class Solution {
public:
    bool isVowel(char &ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        unordered_map<char, int> mp;

        vector<int> nextCons(n);
        int lastCons = n;

        for(int i = n - 1; i >= 0; i--)
        {
            nextCons[i] = lastCons;
            if(!isVowel(word[i])) lastCons = i;
        }

        int i = 0, j = 0, cons = 0;
        long long ans = 0;

        while(j < n)
        {
            char ch = word[j];
            if(isVowel(ch))
            {
                mp[ch]++;
            }
            else cons++;

            while(i < n && cons > k)
            {
                char ch = word[i];
                if(isVowel(ch))
                {
                    mp[ch]--;
                    if(mp[ch] == 0) mp.erase(ch);
                }
                else cons--;
                i++;
            }

            while(i < n && mp.size() == 5 && cons == k)
            {
                int idx = nextCons[j];
                ans += idx - j;
                char ch = word[i];
                if(isVowel(ch)) {
                    mp[ch]--;
                    if(mp[ch] == 0) {
                        mp.erase(ch);
                    }
                } else {
                    cons--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};