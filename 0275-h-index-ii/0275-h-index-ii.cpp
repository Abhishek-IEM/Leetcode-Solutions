class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), hmax = 0;
        //sort(citations.begin(), citations.end());
        for(int i = 0; i < n; i++)
        {
            int h = min(n - i, citations[i]);
            hmax = max(h, hmax);
        }
        return hmax;
    }
};