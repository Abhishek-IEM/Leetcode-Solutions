class Solution {
public:
    string triangleType(vector<int>& nums) {

        bool valid = (nums[0] + nums[1] > nums[2]) &&
                     (nums[0] + nums[2] > nums[1]) &&
                     (nums[1] + nums[2] > nums[0]);

        if(!valid) {
            return "none";
        }
        
        int a = nums[0], b = nums[1], c = nums[2];

        if((a == b) && (b == c) && (a == c)) return "equilateral";
        else if((a != b) && (b != c) && (a != c)) return "scalene";
        else return "isosceles";
    }
};