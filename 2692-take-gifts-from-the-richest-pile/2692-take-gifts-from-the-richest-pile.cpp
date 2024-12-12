class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq;
        for(int i = 0; i < gifts.size(); i++) pq.push(gifts[i]);
        long long ans = 0;
        while(k--)
        {
            long long x = pq.top();
            pq.pop();
            long long y = floor(sqrt(x));
            pq.push(y);
        }
        while(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};