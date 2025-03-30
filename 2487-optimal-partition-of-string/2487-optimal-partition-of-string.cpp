class Solution {
public:
    int partitionString(string s) {
        unordered_set<int> seen;

        int ans = 1;

        for(char c: s)
        {
            if(seen.count(c))
            {
                ans++;
                seen.clear();
            }
            seen.insert(c);
        }
        return ans;
    }
};