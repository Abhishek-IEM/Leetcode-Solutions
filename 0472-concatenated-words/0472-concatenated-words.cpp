class Solution {
public:
    bool isConcat(string word, unordered_set<string> &st, unordered_map<string, bool> &mp)
    {
        if(mp.find(word) != mp.end()) return mp[word];
        int l = word.length();
        for(int i = 0; i < l; i++)
        {
            string prefix = word.substr(0, i + 1);
            string suffix = word.substr(i + 1);

            if((st.find(prefix) != st.end() && st.find(suffix) != st.end()) ||
                st.find(prefix) != st.end() && isConcat(suffix, st, mp)) return mp[word] = true;
        }
        return mp[word] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();

        vector<string> ans;
    
        unordered_map<string, bool> mp;

        unordered_set<string> st(begin(words), end(words));

        for(int i = 0; i < n; i++)
        {
            if(isConcat(words[i], st, mp)) ans.push_back(words[i]);
        }
        return ans;
    }
};