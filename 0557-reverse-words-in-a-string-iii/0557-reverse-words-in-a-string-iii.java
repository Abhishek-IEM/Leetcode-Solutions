class Solution {
    public String reverseWords(String s) {
        char arr[] = s.toCharArray();
        int len = arr.length;

        int sp = 0;

        for(int ep = 0; ep <= len; ep++)
        {
            if(ep == len || arr[ep] == ' ')
            {
                reverse(arr, sp, ep - 1);
                sp = ep + 1;
            }
        }
        return new String(arr);
    }
    public static void reverse(char arr[], int sp, int ep)
    {
        while(sp < ep)
        {
            char temp = arr[sp];
            arr[sp] = arr[ep];
            arr[ep] = temp;
            sp++;
            ep--;
        }
    }
}