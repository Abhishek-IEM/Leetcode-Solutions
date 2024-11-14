class Solution {
public:
    bool isPossileDist(int x, vector<int>& quantities, int shops) {
        for(int &products : quantities)
        {
            shops -= (products + x - 1)/x;
            if(shops < 0) return false;
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size(), maxi = quantities[0];
        for(int i = 0; i < m; i++)
        {
            maxi = max(maxi, quantities[i]);
        }
        int l = 1, r = maxi, ans = 0;;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(isPossileDist(mid, quantities, n))
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};