class Solution {
public:
    int M = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        int count = 0, odd = 0, even = 1, sum = 0;

        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            if(sum % 2 == 0)
            {
                count = (count + odd) % M;
                even++;
            }
            else{
                count = (count + even) % M;
                odd++;
            }
        }
        return count;
    }
};