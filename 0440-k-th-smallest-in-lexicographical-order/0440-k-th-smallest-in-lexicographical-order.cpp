class Solution {
public:
     int Count(long curr, long next, int n) {
        int countNum = 0;

        while(curr <= n) {
            countNum += (next - curr);

            curr *= 10;
            next *= 10;

            next = min(next, long(n+1));
        }

        return countNum;
    }


    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1; //Since we start from the first number (1), we need k-1 more numbers

        while(k > 0) {
            int count = Count(curr, curr+1, n);
            if(count  <= k) {
                curr++;
                k -= count; //skipping the elements under curr prefix tree
            } else {
                curr *= 10;
                k -= 1;
            }
        }

        return curr;
    }
};