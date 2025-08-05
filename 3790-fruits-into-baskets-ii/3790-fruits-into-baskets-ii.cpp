class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size();
        int unplaced = 0;

        for (int i = 0; i < n; i++) {
            bool placed = false;
            // For each fruit, check all baskets from left to right
            for (int j = 0; j < m; j++) {
                if (baskets[j] >= fruits[i]) {
                    baskets[j] = -1;  // Mark basket as used
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                unplaced++;
            }
        }
        return unplaced;
    }
};
