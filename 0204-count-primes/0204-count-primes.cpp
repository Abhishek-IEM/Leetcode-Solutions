class Solution {
public:
    void fillSieve(vector<bool>& sieve)
    {
        int n = sieve.size()-1;
        for(int i=2;i*i<=n;i++)
        {
            if (sieve[i]){
                for(int j=i*2;j<=n;j+=i)
                {
                    sieve[j] = 0;
                }
            }
        }
    }
    int countPrimes(int n) {
        if(n<=2) return 0;
        n = n - 1;
        int count = 1;
        vector<bool> sieve(n+1,1);
        fillSieve(sieve);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=3;i<=n;i+=2)
        {
            if(sieve[i] == 1) count++;
        }
        return count;
    }
};