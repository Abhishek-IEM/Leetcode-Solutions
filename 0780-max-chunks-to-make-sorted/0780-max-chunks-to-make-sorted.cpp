class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxTillNow = -1, count = 0;
        for(int i = 0; i < n; i++)
        {
            maxTillNow = max(maxTillNow, arr[i]);
            if(maxTillNow == i) count++;
        }
        return count;
    }
};