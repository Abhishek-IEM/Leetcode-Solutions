class Solution {
public:
    int customBinary(vector<vector<int>>& items, int queryPrice)
    {
        int l = 0, r = items.size() - 1, mid, maxB = 0;
        while(l <= r)
        {
            mid = l + (r - l)/2;
            if(items[mid][0] > queryPrice)
            {
                r = mid - 1;
            }
            else
            {
                maxB = max(maxB, items[mid][1]);
                l = mid + 1;
            }
        }
        return maxB;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), m = queries.size();
        sort(items.begin(), items.end());
        vector<int> result(m);
        int maxBeauty = items[0][1];
        for(int i = 1; i < n; i++)
        {
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }
        for(int i = 0; i < m; i++)
        {
            int queryPrice = queries[i];
            result[i] = customBinary(items, queryPrice);
        }
        return result;
    }
};