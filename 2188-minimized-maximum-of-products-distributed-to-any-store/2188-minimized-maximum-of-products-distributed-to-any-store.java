class Solution {
    public int minimizedMaximum(int n, int[] q) {
        int s = 1, e = Integer.MIN_VALUE;

        for(int i = 0; i < q.length; i++)
        {
            if(q[i] > e) e = q[i];
        }

        int ans = -1;

        while(s <= e)
        {
            int mid = s + (e - s)/2;
            if(isPossible(q, mid, n))
            {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }

    boolean isPossible(int[] q, int mid, int store)
    {
        int sum = 0;

        for(int i = 0; i < q.length; i++)
        {
            sum += q[i] / mid;

            if(q[i] % mid != 0) sum++;

            if(sum > store) return false;
        }

        return true;
    }
}