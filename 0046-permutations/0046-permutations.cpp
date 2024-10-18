class Solution {
public:
    void permut(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp,  vector<bool> & visited)
    {
        if(visited.size() == temp.size())
        {
            ans.push_back(temp);
            return;
        }
        unordered_set<int> seen;
        for(int i = 0; i < visited.size(); i++)
        {
            if(visited[i] || seen.find(nums[i]) != seen.end()) continue;
            seen.insert(nums[i]);

            if(visited[i] == 0)
            {
                visited[i] = 1;
                temp.push_back(nums[i]);
                permut(nums, ans, temp, visited);
                visited[i] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(), 0);
        vector<int> temp;
        permut(nums, ans, temp, visited);
        return ans;
    }
};