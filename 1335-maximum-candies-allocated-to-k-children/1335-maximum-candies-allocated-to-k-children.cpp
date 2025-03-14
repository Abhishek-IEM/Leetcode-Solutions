class Solution {
public:
    bool canDist(vector<int>& candies, long long k, int mid)
    {
        int n = candies.size();
        
        for(int i = 0; i < n; i++)
        {
            k -= candies[i] / mid;

            if(k <= 0) return true;
        }
        return k <= 0;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        int n =candies.size(), maxc = 0;
        long long total = 0;

        for(int i = 0; i < n; i++){
            maxc = max(maxc, candies[i]);
            total += candies[i];
        }

        if(total < k) return 0;

        int l = 1, r = maxc, ans = 0;

        while(l <= r)
        {
            int mid = l + (r - l) / 2;

            if(canDist(candies, k, mid)){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};