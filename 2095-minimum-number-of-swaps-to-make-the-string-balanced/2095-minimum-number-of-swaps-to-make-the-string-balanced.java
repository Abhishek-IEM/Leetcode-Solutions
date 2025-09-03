class Solution {
    public int minSwaps(String s) {
        Stack<Character> stack = new Stack<Character>();

        for(int i = 0; i < s.length(); i++)
        {
            char ch = s.charAt(i);
            if(ch == '[') stack.push(ch);
            else
            {
                if(stack.isEmpty() || stack.peek() == ']') stack.push(ch);
                else stack.pop();
            }
        }

        int total = stack.size();
        int close = total / 2;
        return (close + 1)/2;
    }
}