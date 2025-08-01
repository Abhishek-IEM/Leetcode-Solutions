class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int m = numRows;
        vector<vector<int>> ans;
        for(int i=0;i<m;i++)
        {
            vector<int> v(i+1);
            ans.push_back(v);
            for(int j=0;j<=i;j++)
            {
                if(j==0||j==i) 
                  ans[i][j]=1;
                else 
                  ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
            }
        }
        return ans;
    }
};