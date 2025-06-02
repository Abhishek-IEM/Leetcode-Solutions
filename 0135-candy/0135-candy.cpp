class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n;

        int i = 1;
        while(i < n)
        {
            if(ratings[i] == ratings[i - 1]){
                i++;
                continue;
            }

            //increasing slope
            int peak = 0;
            while(ratings[i] > ratings[i - 1]){
                peak++;
                candy += peak;
                i++;

                if(i == n) return candy;
            }

            //decreasing slope
            int dip = 0;
            while(i < n && ratings[i] < ratings[i - 1]){
                dip++;
                candy += dip;
                i++;
            }

            candy -= min(peak, dip);
        }
        return candy;
    }
};