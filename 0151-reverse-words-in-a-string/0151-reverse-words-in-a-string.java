class Solution {
    public String reverseWords(String s) {
        String arr[] = s.split(" ");
        StringBuilder sb = new StringBuilder();

        for(int i = arr.length - 1; i >= 0; i--)
        {
            if(arr[i].length() == 0) continue;
            if(sb.length() == 0) sb.append(arr[i]);
            else{
                sb.append(" ");
                sb.append(arr[i]);
            }
        }

        return sb.toString();
    }
}