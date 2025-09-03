class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack<>();

        for(int i = 0; i < asteroids.length; i++)
        {
            if(stack.isEmpty() || asteroids[i] > 0) stack.push(asteroids[i]);
            else
            {
                while(!stack.isEmpty())
                {
                    int top = stack.peek();
                    if(top < 0) 
                    {
                        stack.push(asteroids[i]);
                        break;
                    }
                    int val = Math.abs(asteroids[i]);
                    if(val == top)
                    {
                        stack.pop();
                        break;
                    }
                    else if(val < top) break;
                    else
                    {
                        stack.pop();
                        if(stack.isEmpty())
                        {
                            stack.push(asteroids[i]);
                            break;
                        }
                    }
                }
            }
        }
        int len = stack.size();
        int ans[] = new int[len];

        for(int i = len - 1; i >= 0; i--)
        {
            ans[i] = stack.pop();
        }

        return ans;
    }
}