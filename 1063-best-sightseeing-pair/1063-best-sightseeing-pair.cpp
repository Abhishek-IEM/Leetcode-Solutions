class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        priority_queue<int> pq;
        pq.push(values[0]);

        int result = 0;

        for(int j = 1; j < n; j++)
        {
            int x = values[j] - j;
            int y = pq.top();
            result = max(result, x + y);
            pq.push(values[j] + j);
        }
        return result;
    }
};