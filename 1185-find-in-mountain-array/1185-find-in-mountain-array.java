/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int n = mountainArr.length();
        int s = 0, e = n - 1, mid = -1;

        while(s <= e)
        {
            mid = s + (e - s)/2;
            int cur = mountainArr.get(mid);
            if(mid != 0 && mid != n - 1 && cur > mountainArr.get(mid - 1) && cur > mountainArr.get(mid + 1)){
                if(cur == target) return mid;
                break;
            }
            else if(mid != n - 1 && cur < mountainArr.get(mid + 1)) s = mid + 1;
            else e = mid - 1;
        }

        //search in 1st half
        s = 0; e = mid;
        while(s <= e)
        {
            int m = s + (e - s) / 2;
            int cur = mountainArr.get(m);
            if(cur == target) return m;
            else if(cur > target) e = m - 1;
            else s = m + 1;
        }

        //search in 2nd half
        s = mid + 1; e = n - 1;
        while(s <= e)
        {
            int m = s + (e - s) / 2;
            int cur = mountainArr.get(m);
            if(cur == target) return m;
            else if(cur > target) s = m + 1;
            else e = m - 1;
        }

        return -1;
    }
}