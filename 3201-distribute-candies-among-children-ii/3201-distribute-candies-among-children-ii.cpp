class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;

        int minch1 = max(0, n - 2 * limit);
        int maxch2 = min(n, limit);

        for(int i = minch1; i <= maxch2; i++)
        {
            int N = n - i;

            int minch2 = max(0, N - limit);
            int maxch2 = min(N, limit);

            ways += maxch2 - minch2 + 1; 
        }

        return ways;
    }
};