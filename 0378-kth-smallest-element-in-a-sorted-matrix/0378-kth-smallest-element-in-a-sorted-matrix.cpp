class Solution {
public:
    int count(vector<vector<int>>& matrix, int ele)
    {
        int n = matrix.size(), r = 0, c = n - 1, cnt = 0;

        while(r < n && c >= 0)
        {
            if(matrix[r][c] <= ele)
            {
                cnt += c + 1;
                r++;
            }
            else c--;
        }
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), s = matrix[0][0], ans = 0, e = matrix[n - 1][n - 1];

        while(s <= e)
        {
            int mid = s + (e - s)/2;
            int cnt = count(matrix, mid);
            if(cnt < k) s = mid + 1;
            else{
                ans = mid;
                e = mid - 1;
            }
        }
        return ans;
    }
};