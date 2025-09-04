class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a = abs(x-z);
        int b = abs(y-z);
        return a==b ? 0 : 2 - (a < b);
    }
};