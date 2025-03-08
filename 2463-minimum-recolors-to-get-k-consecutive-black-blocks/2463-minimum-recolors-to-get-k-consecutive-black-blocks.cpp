class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(), ans = k;
        int i = 0, j = 0, w = 0;

        while(j < n)
        {
            if(blocks[j] == 'W') w++;

            if(j - i + 1 == k)
            {
                ans = min(ans, w);
                if(blocks[i] == 'W') w--;
                i++;
            }
            
            j++;
        }
        return ans;
    }
};