class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int s = 1, e = Integer.MIN_VALUE;

        for(int i = 0; i < nums.length; i++)
        {
            if(nums[i] > e) e = nums[i];
        }

        int ans = -1;

        while(s <= e)
        {
            int mid = s + (e - s)/2;
            if(isDivisionPossible(nums, mid, threshold)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }

        return ans;
    }

    boolean isDivisionPossible(int[] nums, int d, int th)
    {
        int sum = 0;

        for(int i = 0; i < nums.length; i++)
        {
            sum += nums[i]/d;
            
            if(nums[i] % d != 0) sum++;

            if(sum > th) return false;
        }

        return true;
    }
}