class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> count(101);

        int total = 0, maxFreq = 0;

        for(int &num: nums)
        {
            count[num]++;
            int freq = count[num];

            if(freq > maxFreq)
            {
                maxFreq = freq;
                total = maxFreq;
            }
            else if(freq == maxFreq)
            {
                total += maxFreq;
            }
        }
        return total;
    }
};