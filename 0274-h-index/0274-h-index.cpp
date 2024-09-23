class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int hmax = 0;
        for(int i = 0; i < n; i++)
        {
            int h = min(citations[i], n - i);
            hmax = max(h, hmax);
        }
        return hmax;
    }
};