class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        int k = 0;
        vector<int> ans(m+n);
        while(i<n && j<m)
        {
            if(nums1[i]<nums2[j])
            {
                ans[k] = nums1[i];
                i++;
                k++;
            }
            else
            {
                ans[k] = nums2[j];
                j++;
                k++;
            }
        }
        if(i==n)
        {
            while(j<m)
            {
                ans[k] = nums2[j];
                k++;
                j++;
            }
        }
        if(j==m)
        {
            while(i<n)
            {
                ans[k] = nums1[i];
                k++;
                i++;
            }
        }
        double median = 0.0;
        int s = ans.size();
        if(s%2!=0)
        {
            median = ans[s/2];
        }
        else
        {
            median = (ans[s/2-1] + ans[s/2]);
            median = median/2;
        }
        return median;
    }
};