class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while(i < n && j < m)
        {
            if(nums1[i][0] == nums2[j][0])
            {
                vector<int> v(2);
                v[0] = nums1[i][0];
                v[1] = nums1[i][1] + nums2[j][1];
                ans.push_back(v);
                i++;
                j++;
            }
            else if(nums1[i][0] < nums2[j][0])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else 
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i < n)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while(j < m)
        {
            ans.push_back(nums2[j]);
            j++;
        }
        return ans;
    }
};