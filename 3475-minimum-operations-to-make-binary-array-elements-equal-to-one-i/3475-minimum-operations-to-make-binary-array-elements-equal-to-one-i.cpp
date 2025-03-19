class Solution {
public:
     int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;
        deque<int> flipQue;
        int flipCountFromPastForCurri = 0;

        for(int i = 0; i < n; i++) {
            if(i >= k){
                flipCountFromPastForCurri -= flipQue.front();
                flipQue.pop_front();
            }
            
            if(flipCountFromPastForCurri % 2 == nums[i]) {
                if(i+k > n){
                    return -1;
                }
                flipCountFromPastForCurri++;
                flipQue.push_back(1);
                flips++;
            } else {
                flipQue.push_back(0);
            }
        }

        return flips;
    }

    int minOperations(vector<int>& nums) {
        return minKBitFlips(nums, 3);
    }
};