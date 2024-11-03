class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() > goal.size()) return false;
        string ans = s;
        ans += s;
        if(ans.find(goal) < ans.length()) return true;
        return false;
    }
};