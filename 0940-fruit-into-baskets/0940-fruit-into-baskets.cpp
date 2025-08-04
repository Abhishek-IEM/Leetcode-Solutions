class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), i = 0, j = 0, count = 0;

        unordered_map<int, int> mp;

        while(j < n)
        {
            mp[fruits[j]]++;

            if(mp.size() <= 2)
            {
                count = max(count, j - i + 1);
            }
            else
            {
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }
            j++;
        }

        return count;
    }
};