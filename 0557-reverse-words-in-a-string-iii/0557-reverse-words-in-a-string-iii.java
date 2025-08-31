class Solution {
    public String reverseWords(String s) {
        StringBuilder ans = new StringBuilder();
        StringBuilder word = new StringBuilder();

        for(char c: s.toCharArray())
        {
            if(c == ' ')
            {
                ans.append(word.reverse());
                ans.append(" ");
                word.setLength(0);
            }
            else word.append(c);
        }
        ans.append(word.reverse());

        return ans.toString();
    }
}