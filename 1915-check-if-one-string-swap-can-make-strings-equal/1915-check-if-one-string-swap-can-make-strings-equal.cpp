class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        int n = s1.length();
        
        int diffs = 0;

        int firstIdx = 0;
        int secondIdx = 0;

        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                diffs++;

                if(diffs > 2) {
                    return false;
                } else if(diffs == 1) {
                    firstIdx = i;
                } else {
                    secondIdx = i;
                }

            }
        }

        return s1[firstIdx] == s2[secondIdx] && s1[secondIdx] == s2[firstIdx];

    }
};