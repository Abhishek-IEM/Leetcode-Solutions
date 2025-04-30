class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;

        for (int num : nums) {
            string str = to_string(num);
            if (str.length() % 2 == 0)
                result++;
        }

        return result;
    }
};